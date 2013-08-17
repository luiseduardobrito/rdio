/* Networking.c generated by valac 0.20.1, the Vala compiler
 * generated from Networking.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; tab-width: 4 -*-*/
/*-
 * Copyright (c) 2013 Birdie Developers (http://launchpad.net/birdie)
 *
 * This software is licensed under the GNU General Public License
 * (version 3 or later). See the COPYING file in this distribution.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this software; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authored by: Ivo Nunes <ivo@elementaryos.org>
 *              Vasco Nunes <vascomfnunes@gmail.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))



gboolean rdio_utils_check_internet_connection (void);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


gboolean rdio_utils_check_internet_connection (void) {
	gboolean result = FALSE;
	gchar* _tmp0_;
	gchar* host;
	GError * _inner_error_ = NULL;
	_tmp0_ = g_strdup ("www.google.com");
	host = _tmp0_;
	{
		GResolver* _tmp1_ = NULL;
		GResolver* resolver;
		GList* _tmp2_ = NULL;
		GList* addresses;
		gconstpointer _tmp3_ = NULL;
		GInetAddress* _tmp4_;
		GInetAddress* address;
		GInetAddress* _tmp5_;
		_tmp1_ = g_resolver_get_default ();
		resolver = _tmp1_;
		_tmp2_ = g_resolver_lookup_by_name (resolver, host, NULL, &_inner_error_);
		addresses = _tmp2_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (resolver);
			goto __catch11_g_error;
		}
		_tmp3_ = g_list_nth_data (addresses, (guint) 0);
		_tmp4_ = _g_object_ref0 ((GInetAddress*) _tmp3_);
		address = _tmp4_;
		_tmp5_ = address;
		if (_tmp5_ == NULL) {
			result = FALSE;
			_g_object_unref0 (address);
			__g_list_free__g_object_unref0_0 (addresses);
			_g_object_unref0 (resolver);
			_g_free0 (host);
			return result;
		}
		_g_object_unref0 (address);
		__g_list_free__g_object_unref0_0 (addresses);
		_g_object_unref0 (resolver);
	}
	goto __finally11;
	__catch11_g_error:
	{
		GError* e = NULL;
		GError* _tmp6_;
		const gchar* _tmp7_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = e;
		_tmp7_ = _tmp6_->message;
		g_debug ("Networking.vala:30: %s\n", _tmp7_);
		result = FALSE;
		_g_error_free0 (e);
		_g_free0 (host);
		return result;
	}
	__finally11:
	if (_inner_error_ != NULL) {
		_g_free0 (host);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	result = TRUE;
	_g_free0 (host);
	return result;
}



