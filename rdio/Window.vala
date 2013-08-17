/*-
 * Copyright (c) 2011-2012 Scott Ringwelski <sgringwe@mtu.edu>
 *
 * Originally Written by Scott Ringwelski for Rdio Music Player
 * Rdio Music Player: http://www.github.com/sgringwe/rdio
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

using Gtk;

public class Rdio.Window : Gtk.Window {
	public static Gtk.Application app { get; private set; }
	
	TopGradient titlebar;
    OverlayLabel overlay_label;
	public WebKit.WebView webview;
	Gtk.ScrolledWindow scrolled_window;

	bool window_maximized;
    
    string INJECTED_CONTROLS = """<nav id="injectedNavigationControls" class="ViewToggle clearfix" style="float: left; margin: 20px 0px 20px 25px;"><ul><li class="first"><a href="#" onclick="history.back();">&lt;</a></li><li class="last"><a href="#" onclick="history.forward();">&gt;</a></li></ul></nav>""";
    
	string INJECT_JS = """
		var timer = null;
		timer = setInterval(function(){
            if ($('#injectedNavigationControls').length == 0) {
				$('#header').prepend('%s');
				console.log('injecting into header');
            }
        },1000);
	""";

	public Window (Gtk.Application gtk_app) {
		set_application (app);

		// Window styling
		// set_app_paintable (true);
		// set_decorated (false);
		set_title ("");
		set_visual (get_screen ().get_rgba_visual());
		// set_icon (IconTheme.get_default ().load_icon ("rdio", 48, 0));

		// TODO: Save window size in dconf
		window_position = Gtk.WindowPosition.CENTER;
		set_default_size (1400, 700);
        
        Overlay overlay = new Overlay();
		Box box = new Box (Orientation.VERTICAL, 0);
		titlebar = new TopGradient ();
		webview = new WebKit.WebView ();
		scrolled_window = new ScrolledWindow (null, null);

		scrolled_window.set_policy (PolicyType.AUTOMATIC, PolicyType.AUTOMATIC);
		scrolled_window.add (webview);

		box.pack_start (titlebar, false, false, 0);
		box.pack_end (scrolled_window, true, true, 0);
        
        overlay.add (box);
		add (overlay);

		// Configure the browser
		var settings = webview.get_settings ();
		settings.enable_plugins = true;
		settings.enable_private_browsing = true;
		settings.enable_page_cache = true;
		settings.enable_default_context_menu = false;
		webview.set_settings (settings);

		setup_cookies ();
		webview.open ("https://www.rdio.com/browse/charts/albums/");

		set_default_size (App.settings.window_width, App.settings.window_height);
		if (App.settings.window_state == Settings.WindowState.MAXIMIZED) {
		  window_maximized = true;
		  maximize();
		}
        
        overlay_label = new Rdio.OverlayLabel("No Internet Connection");
        overlay.add_overlay (overlay_label);

		show_all();

		destroy.connect (on_quit);
		window_state_event.connect(window_state_changed);
		webview.load_finished.connect (load_finished);
        
        // Check internet connection every 15 seconds
        check_internet_connection ();
        Timeout.add(15000, () => {
			check_internet_connection ();
			return true;
		});
	}
    
    void check_internet_connection () {
        if (Rdio.Utils.check_internet_connection()) {
            overlay_label.set_visible (false);
        }
        else {
            overlay_label.set_visible (true);
        }
        //overlay_label.set_visible (true);
    }
	
	void load_finished(WebKit.WebFrame frame) {
        
        // This is crap. this call back is called ~3 times and so we have a js loop
        // going 3 times every second. But Rdio is kind of crappy because we can't
        // just listen to dom ready since all loading is done dynamically.
        // So, we have 3 js loops waiting and if it notices the nav is missing
        // it re-injects it.
        webview.execute_script (INJECT_JS.printf (INJECTED_CONTROLS));
	}

	public void initialize_events () {
		  App.middleware.changed.connect (song_changed);
	}

	void setup_cookies () {
		var user_rdio_folder = GLib.File.new_for_path (GLib.Path.build_filename (Environment.get_user_data_dir (), "rdio"));

		// Make sure our config folder exists
		if (!user_rdio_folder.query_exists ()) {
		  try {
				user_rdio_folder.make_directory_with_parents (null);
		  }
		  catch (GLib.Error err) {
				critical ("Could not create beatbox folder in data directory: %s\n", err.message);
		  }
		}

		// This is where cookie will be stored
		var user_rdio_cookie_file = GLib.Path.build_filename (user_rdio_folder.get_path (), "cookies.dat");

		// Set up webkit and soup to persist the cookies
		var session = WebKit.get_default_session ();
		var cookiejar = new Soup.CookieJarText (user_rdio_cookie_file, false);
		session.add_feature (cookiejar);
	}

	void song_changed () {
		  set_title ("DEV | " + App.middleware.title + " " + _("by") + " " + App.middleware.artist + " " + _("on") + " " + App.middleware.album);
	}

	bool window_state_changed(Gdk.EventWindowState event) {
		window_maximized = ((event.new_window_state & (Gdk.WindowState.MAXIMIZED | Gdk.WindowState.FULLSCREEN)) != 0);
		
		return false;
	}

	void on_quit() {
		// Stop listening to window state changes
		window_state_event.disconnect(window_state_changed);

		// Terminate Libnotify
		#if HAVE_LIBNOTIFY
		Notify.uninit ();
		#endif
		
		// Save UI Information
		if (window_maximized) {
				App.settings.window_state = Settings.WindowState.MAXIMIZED;
		}
		else {
				App.settings.window_state = Settings.WindowState.NORMAL;
				App.settings.window_width = get_allocated_width();
				App.settings.window_height = get_allocated_height();
		}
	}
}
