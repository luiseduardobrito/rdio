/* MediaKeyListener.c generated by valac 0.20.1, the Vala compiler
 * generated from MediaKeyListener.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define TYPE_GNOME_MEDIA_KEYS (gnome_media_keys_get_type ())
#define GNOME_MEDIA_KEYS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GNOME_MEDIA_KEYS, GnomeMediaKeys))
#define IS_GNOME_MEDIA_KEYS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GNOME_MEDIA_KEYS))
#define GNOME_MEDIA_KEYS_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_GNOME_MEDIA_KEYS, GnomeMediaKeysIface))

typedef struct _GnomeMediaKeys GnomeMediaKeys;
typedef struct _GnomeMediaKeysIface GnomeMediaKeysIface;

#define TYPE_GNOME_MEDIA_KEYS_PROXY (gnome_media_keys_proxy_get_type ())
typedef GDBusProxy GnomeMediaKeysProxy;
typedef GDBusProxyClass GnomeMediaKeysProxyClass;
#define _g_free0(var) (var = (g_free (var), NULL))

#define RDIO_TYPE_MEDIA_KEY_LISTENER (rdio_media_key_listener_get_type ())
#define RDIO_MEDIA_KEY_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RDIO_TYPE_MEDIA_KEY_LISTENER, RdioMediaKeyListener))
#define RDIO_MEDIA_KEY_LISTENER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RDIO_TYPE_MEDIA_KEY_LISTENER, RdioMediaKeyListenerClass))
#define RDIO_IS_MEDIA_KEY_LISTENER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RDIO_TYPE_MEDIA_KEY_LISTENER))
#define RDIO_IS_MEDIA_KEY_LISTENER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RDIO_TYPE_MEDIA_KEY_LISTENER))
#define RDIO_MEDIA_KEY_LISTENER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RDIO_TYPE_MEDIA_KEY_LISTENER, RdioMediaKeyListenerClass))

typedef struct _RdioMediaKeyListener RdioMediaKeyListener;
typedef struct _RdioMediaKeyListenerClass RdioMediaKeyListenerClass;
typedef struct _RdioMediaKeyListenerPrivate RdioMediaKeyListenerPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define RDIO_TYPE_MIDDLEWARE (rdio_middleware_get_type ())
#define RDIO_MIDDLEWARE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RDIO_TYPE_MIDDLEWARE, RdioMiddleware))
#define RDIO_MIDDLEWARE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RDIO_TYPE_MIDDLEWARE, RdioMiddlewareClass))
#define RDIO_IS_MIDDLEWARE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RDIO_TYPE_MIDDLEWARE))
#define RDIO_IS_MIDDLEWARE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RDIO_TYPE_MIDDLEWARE))
#define RDIO_MIDDLEWARE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RDIO_TYPE_MIDDLEWARE, RdioMiddlewareClass))

typedef struct _RdioMiddleware RdioMiddleware;
typedef struct _RdioMiddlewareClass RdioMiddlewareClass;

struct _GnomeMediaKeysIface {
	GTypeInterface parent_iface;
	void (*GrabMediaPlayerKeys) (GnomeMediaKeys* self, const gchar* application, guint32 time, GError** error);
	void (*ReleaseMediaPlayerKeys) (GnomeMediaKeys* self, const gchar* application, GError** error);
};

struct _RdioMediaKeyListener {
	GObject parent_instance;
	RdioMediaKeyListenerPrivate * priv;
};

struct _RdioMediaKeyListenerClass {
	GObjectClass parent_class;
};

struct _RdioMediaKeyListenerPrivate {
	GnomeMediaKeys* media_object;
};


static gpointer rdio_media_key_listener_parent_class = NULL;

GType gnome_media_keys_proxy_get_type (void) G_GNUC_CONST;
guint gnome_media_keys_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
GType gnome_media_keys_get_type (void) G_GNUC_CONST;
void gnome_media_keys_GrabMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, guint32 time, GError** error);
void gnome_media_keys_ReleaseMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, GError** error);
static void g_cclosure_user_marshal_VOID__STRING_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void gnome_media_keys_proxy_g_signal (GDBusProxy* proxy, const gchar* sender_name, const gchar* signal_name, GVariant* parameters);
static void _dbus_handle_gnome_media_keys_media_player_key_pressed (GnomeMediaKeys* self, GVariant* parameters);
static void gnome_media_keys_proxy_GrabMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, guint32 time, GError** error);
static void gnome_media_keys_proxy_ReleaseMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, GError** error);
static void gnome_media_keys_proxy_gnome_media_keys_interface_init (GnomeMediaKeysIface* iface);
static void _dbus_gnome_media_keys_GrabMediaPlayerKeys (GnomeMediaKeys* self, GVariant* parameters, GDBusMethodInvocation* invocation);
static void _dbus_gnome_media_keys_ReleaseMediaPlayerKeys (GnomeMediaKeys* self, GVariant* parameters, GDBusMethodInvocation* invocation);
static void gnome_media_keys_dbus_interface_method_call (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* method_name, GVariant* parameters, GDBusMethodInvocation* invocation, gpointer user_data);
static GVariant* gnome_media_keys_dbus_interface_get_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GError** error, gpointer user_data);
static gboolean gnome_media_keys_dbus_interface_set_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GVariant* value, GError** error, gpointer user_data);
static void _dbus_gnome_media_keys_media_player_key_pressed (GObject* _sender, const gchar* application, const gchar* key, gpointer* _data);
static void _gnome_media_keys_unregister_object (gpointer user_data);
GType rdio_media_key_listener_get_type (void) G_GNUC_CONST;
#define RDIO_MEDIA_KEY_LISTENER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), RDIO_TYPE_MEDIA_KEY_LISTENER, RdioMediaKeyListenerPrivate))
enum  {
	RDIO_MEDIA_KEY_LISTENER_DUMMY_PROPERTY
};
RdioMediaKeyListener* rdio_media_key_listener_new (void);
RdioMediaKeyListener* rdio_media_key_listener_construct (GType object_type);
static void rdio_media_key_listener_mediaKeyPressed (RdioMediaKeyListener* self, GObject* bus, const gchar* application, const gchar* key);
static void _rdio_media_key_listener_mediaKeyPressed_gnome_media_keys_media_player_key_pressed (GnomeMediaKeys* _sender, const gchar* application, const gchar* key, gpointer self);
void rdio_media_key_listener_releaseMediaKeys (RdioMediaKeyListener* self);
GType rdio_middleware_get_type (void) G_GNUC_CONST;
RdioMiddleware* rdio_app_get_middleware (void);
void rdio_middleware_previous (RdioMiddleware* self);
void rdio_middleware_playpause (RdioMiddleware* self);
void rdio_middleware_next (RdioMiddleware* self);
static void rdio_media_key_listener_finalize (GObject* obj);

static const GDBusArgInfo _gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_application = {-1, "application", "s"};
static const GDBusArgInfo _gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_time = {-1, "time", "u"};
static const GDBusArgInfo * const _gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_in[] = {&_gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_application, &_gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_time, NULL};
static const GDBusArgInfo * const _gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_out[] = {NULL};
static const GDBusMethodInfo _gnome_media_keys_dbus_method_info_GrabMediaPlayerKeys = {-1, "GrabMediaPlayerKeys", (GDBusArgInfo **) (&_gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_in), (GDBusArgInfo **) (&_gnome_media_keys_dbus_arg_info_GrabMediaPlayerKeys_out)};
static const GDBusArgInfo _gnome_media_keys_dbus_arg_info_ReleaseMediaPlayerKeys_application = {-1, "application", "s"};
static const GDBusArgInfo * const _gnome_media_keys_dbus_arg_info_ReleaseMediaPlayerKeys_in[] = {&_gnome_media_keys_dbus_arg_info_ReleaseMediaPlayerKeys_application, NULL};
static const GDBusArgInfo * const _gnome_media_keys_dbus_arg_info_ReleaseMediaPlayerKeys_out[] = {NULL};
static const GDBusMethodInfo _gnome_media_keys_dbus_method_info_ReleaseMediaPlayerKeys = {-1, "ReleaseMediaPlayerKeys", (GDBusArgInfo **) (&_gnome_media_keys_dbus_arg_info_ReleaseMediaPlayerKeys_in), (GDBusArgInfo **) (&_gnome_media_keys_dbus_arg_info_ReleaseMediaPlayerKeys_out)};
static const GDBusMethodInfo * const _gnome_media_keys_dbus_method_info[] = {&_gnome_media_keys_dbus_method_info_GrabMediaPlayerKeys, &_gnome_media_keys_dbus_method_info_ReleaseMediaPlayerKeys, NULL};
static const GDBusArgInfo _gnome_media_keys_dbus_arg_info_media_player_key_pressed_application = {-1, "application", "s"};
static const GDBusArgInfo _gnome_media_keys_dbus_arg_info_media_player_key_pressed_key = {-1, "key", "s"};
static const GDBusArgInfo * const _gnome_media_keys_dbus_arg_info_media_player_key_pressed[] = {&_gnome_media_keys_dbus_arg_info_media_player_key_pressed_application, &_gnome_media_keys_dbus_arg_info_media_player_key_pressed_key, NULL};
static const GDBusSignalInfo _gnome_media_keys_dbus_signal_info_media_player_key_pressed = {-1, "MediaPlayerKeyPressed", (GDBusArgInfo **) (&_gnome_media_keys_dbus_arg_info_media_player_key_pressed)};
static const GDBusSignalInfo * const _gnome_media_keys_dbus_signal_info[] = {&_gnome_media_keys_dbus_signal_info_media_player_key_pressed, NULL};
static const GDBusPropertyInfo * const _gnome_media_keys_dbus_property_info[] = {NULL};
static const GDBusInterfaceInfo _gnome_media_keys_dbus_interface_info = {-1, "org.gnome.SettingsDaemon.MediaKeys", (GDBusMethodInfo **) (&_gnome_media_keys_dbus_method_info), (GDBusSignalInfo **) (&_gnome_media_keys_dbus_signal_info), (GDBusPropertyInfo **) (&_gnome_media_keys_dbus_property_info)};
static const GDBusInterfaceVTable _gnome_media_keys_dbus_interface_vtable = {gnome_media_keys_dbus_interface_method_call, gnome_media_keys_dbus_interface_get_property, gnome_media_keys_dbus_interface_set_property};

void gnome_media_keys_GrabMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, guint32 time, GError** error) {
	g_return_if_fail (self != NULL);
	GNOME_MEDIA_KEYS_GET_INTERFACE (self)->GrabMediaPlayerKeys (self, application, time, error);
}


void gnome_media_keys_ReleaseMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, GError** error) {
	g_return_if_fail (self != NULL);
	GNOME_MEDIA_KEYS_GET_INTERFACE (self)->ReleaseMediaPlayerKeys (self, application, error);
}


static void g_cclosure_user_marshal_VOID__STRING_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__STRING_STRING) (gpointer data1, const char* arg_1, const char* arg_2, gpointer data2);
	register GMarshalFunc_VOID__STRING_STRING callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__STRING_STRING) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_string (param_values + 1), g_value_get_string (param_values + 2), data2);
}


static void gnome_media_keys_base_init (GnomeMediaKeysIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_signal_new ("media_player_key_pressed", TYPE_GNOME_MEDIA_KEYS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__STRING_STRING, G_TYPE_NONE, 2, G_TYPE_STRING, G_TYPE_STRING);
	}
}


GType gnome_media_keys_get_type (void) {
	static volatile gsize gnome_media_keys_type_id__volatile = 0;
	if (g_once_init_enter (&gnome_media_keys_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GnomeMediaKeysIface), (GBaseInitFunc) gnome_media_keys_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType gnome_media_keys_type_id;
		gnome_media_keys_type_id = g_type_register_static (G_TYPE_INTERFACE, "GnomeMediaKeys", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (gnome_media_keys_type_id, G_TYPE_OBJECT);
		g_type_set_qdata (gnome_media_keys_type_id, g_quark_from_static_string ("vala-dbus-proxy-type"), (void*) gnome_media_keys_proxy_get_type);
		g_type_set_qdata (gnome_media_keys_type_id, g_quark_from_static_string ("vala-dbus-interface-name"), "org.gnome.SettingsDaemon.MediaKeys");
		g_type_set_qdata (gnome_media_keys_type_id, g_quark_from_static_string ("vala-dbus-register-object"), (void*) gnome_media_keys_register_object);
		g_once_init_leave (&gnome_media_keys_type_id__volatile, gnome_media_keys_type_id);
	}
	return gnome_media_keys_type_id__volatile;
}


G_DEFINE_TYPE_EXTENDED (GnomeMediaKeysProxy, gnome_media_keys_proxy, G_TYPE_DBUS_PROXY, 0, G_IMPLEMENT_INTERFACE (TYPE_GNOME_MEDIA_KEYS, gnome_media_keys_proxy_gnome_media_keys_interface_init) )
static void gnome_media_keys_proxy_class_init (GnomeMediaKeysProxyClass* klass) {
	G_DBUS_PROXY_CLASS (klass)->g_signal = gnome_media_keys_proxy_g_signal;
}


static void _dbus_handle_gnome_media_keys_media_player_key_pressed (GnomeMediaKeys* self, GVariant* parameters) {
	GVariantIter _arguments_iter;
	gchar* application = NULL;
	GVariant* _tmp0_;
	gchar* key = NULL;
	GVariant* _tmp1_;
	g_variant_iter_init (&_arguments_iter, parameters);
	_tmp0_ = g_variant_iter_next_value (&_arguments_iter);
	application = g_variant_dup_string (_tmp0_, NULL);
	g_variant_unref (_tmp0_);
	_tmp1_ = g_variant_iter_next_value (&_arguments_iter);
	key = g_variant_dup_string (_tmp1_, NULL);
	g_variant_unref (_tmp1_);
	g_signal_emit_by_name (self, "media-player-key-pressed", application, key);
	_g_free0 (application);
	_g_free0 (key);
}


static void gnome_media_keys_proxy_g_signal (GDBusProxy* proxy, const gchar* sender_name, const gchar* signal_name, GVariant* parameters) {
	if (strcmp (signal_name, "MediaPlayerKeyPressed") == 0) {
		_dbus_handle_gnome_media_keys_media_player_key_pressed ((GnomeMediaKeys*) proxy, parameters);
	}
}


static void gnome_media_keys_proxy_init (GnomeMediaKeysProxy* self) {
}


static void gnome_media_keys_proxy_GrabMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, guint32 time, GError** error) {
	GDBusMessage *_message;
	GVariant *_arguments;
	GVariantBuilder _arguments_builder;
	GDBusMessage *_reply_message;
	G_IO_ERROR;
	_message = g_dbus_message_new_method_call (g_dbus_proxy_get_name ((GDBusProxy *) self), g_dbus_proxy_get_object_path ((GDBusProxy *) self), "org.gnome.SettingsDaemon.MediaKeys", "GrabMediaPlayerKeys");
	g_variant_builder_init (&_arguments_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_string (application));
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_uint32 (time));
	_arguments = g_variant_builder_end (&_arguments_builder);
	g_dbus_message_set_body (_message, _arguments);
	_reply_message = g_dbus_connection_send_message_with_reply_sync (g_dbus_proxy_get_connection ((GDBusProxy *) self), _message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, g_dbus_proxy_get_default_timeout ((GDBusProxy *) self), NULL, NULL, error);
	g_object_unref (_message);
	if (!_reply_message) {
		return;
	}
	if (g_dbus_message_to_gerror (_reply_message, error)) {
		g_object_unref (_reply_message);
		return;
	}
	g_object_unref (_reply_message);
}


static void gnome_media_keys_proxy_ReleaseMediaPlayerKeys (GnomeMediaKeys* self, const gchar* application, GError** error) {
	GDBusMessage *_message;
	GVariant *_arguments;
	GVariantBuilder _arguments_builder;
	GDBusMessage *_reply_message;
	G_IO_ERROR;
	_message = g_dbus_message_new_method_call (g_dbus_proxy_get_name ((GDBusProxy *) self), g_dbus_proxy_get_object_path ((GDBusProxy *) self), "org.gnome.SettingsDaemon.MediaKeys", "ReleaseMediaPlayerKeys");
	g_variant_builder_init (&_arguments_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_string (application));
	_arguments = g_variant_builder_end (&_arguments_builder);
	g_dbus_message_set_body (_message, _arguments);
	_reply_message = g_dbus_connection_send_message_with_reply_sync (g_dbus_proxy_get_connection ((GDBusProxy *) self), _message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, g_dbus_proxy_get_default_timeout ((GDBusProxy *) self), NULL, NULL, error);
	g_object_unref (_message);
	if (!_reply_message) {
		return;
	}
	if (g_dbus_message_to_gerror (_reply_message, error)) {
		g_object_unref (_reply_message);
		return;
	}
	g_object_unref (_reply_message);
}


static void gnome_media_keys_proxy_gnome_media_keys_interface_init (GnomeMediaKeysIface* iface) {
	iface->GrabMediaPlayerKeys = gnome_media_keys_proxy_GrabMediaPlayerKeys;
	iface->ReleaseMediaPlayerKeys = gnome_media_keys_proxy_ReleaseMediaPlayerKeys;
}


static void _dbus_gnome_media_keys_GrabMediaPlayerKeys (GnomeMediaKeys* self, GVariant* parameters, GDBusMethodInvocation* invocation) {
	GError* error = NULL;
	GVariantIter _arguments_iter;
	gchar* application = NULL;
	GVariant* _tmp2_;
	guint32 time = 0U;
	GVariant* _tmp3_;
	GDBusMessage* _reply_message;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	g_variant_iter_init (&_arguments_iter, parameters);
	_tmp2_ = g_variant_iter_next_value (&_arguments_iter);
	application = g_variant_dup_string (_tmp2_, NULL);
	g_variant_unref (_tmp2_);
	_tmp3_ = g_variant_iter_next_value (&_arguments_iter);
	time = g_variant_get_uint32 (_tmp3_);
	g_variant_unref (_tmp3_);
	gnome_media_keys_GrabMediaPlayerKeys (self, application, time, &error);
	if (error) {
		g_dbus_method_invocation_return_gerror (invocation, error);
		return;
	}
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	_g_free0 (application);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
}


static void _dbus_gnome_media_keys_ReleaseMediaPlayerKeys (GnomeMediaKeys* self, GVariant* parameters, GDBusMethodInvocation* invocation) {
	GError* error = NULL;
	GVariantIter _arguments_iter;
	gchar* application = NULL;
	GVariant* _tmp4_;
	GDBusMessage* _reply_message;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	g_variant_iter_init (&_arguments_iter, parameters);
	_tmp4_ = g_variant_iter_next_value (&_arguments_iter);
	application = g_variant_dup_string (_tmp4_, NULL);
	g_variant_unref (_tmp4_);
	gnome_media_keys_ReleaseMediaPlayerKeys (self, application, &error);
	if (error) {
		g_dbus_method_invocation_return_gerror (invocation, error);
		return;
	}
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	_g_free0 (application);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
}


static void gnome_media_keys_dbus_interface_method_call (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* method_name, GVariant* parameters, GDBusMethodInvocation* invocation, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	if (strcmp (method_name, "GrabMediaPlayerKeys") == 0) {
		_dbus_gnome_media_keys_GrabMediaPlayerKeys (object, parameters, invocation);
	} else if (strcmp (method_name, "ReleaseMediaPlayerKeys") == 0) {
		_dbus_gnome_media_keys_ReleaseMediaPlayerKeys (object, parameters, invocation);
	} else {
		g_object_unref (invocation);
	}
}


static GVariant* gnome_media_keys_dbus_interface_get_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GError** error, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return NULL;
}


static gboolean gnome_media_keys_dbus_interface_set_property (GDBusConnection* connection, const gchar* sender, const gchar* object_path, const gchar* interface_name, const gchar* property_name, GVariant* value, GError** error, gpointer user_data) {
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return FALSE;
}


static void _dbus_gnome_media_keys_media_player_key_pressed (GObject* _sender, const gchar* application, const gchar* key, gpointer* _data) {
	GDBusConnection * _connection;
	const gchar * _path;
	GVariant *_arguments;
	GVariantBuilder _arguments_builder;
	_connection = _data[1];
	_path = _data[2];
	g_variant_builder_init (&_arguments_builder, G_VARIANT_TYPE_TUPLE);
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_string (application));
	g_variant_builder_add_value (&_arguments_builder, g_variant_new_string (key));
	_arguments = g_variant_builder_end (&_arguments_builder);
	g_dbus_connection_emit_signal (_connection, NULL, _path, "org.gnome.SettingsDaemon.MediaKeys", "MediaPlayerKeyPressed", _arguments, NULL);
}


guint gnome_media_keys_register_object (gpointer object, GDBusConnection* connection, const gchar* path, GError** error) {
	guint result;
	gpointer *data;
	data = g_new (gpointer, 3);
	data[0] = g_object_ref (object);
	data[1] = g_object_ref (connection);
	data[2] = g_strdup (path);
	result = g_dbus_connection_register_object (connection, path, (GDBusInterfaceInfo *) (&_gnome_media_keys_dbus_interface_info), &_gnome_media_keys_dbus_interface_vtable, data, _gnome_media_keys_unregister_object, error);
	if (!result) {
		return 0;
	}
	g_signal_connect (object, "media-player-key-pressed", (GCallback) _dbus_gnome_media_keys_media_player_key_pressed, data);
	return result;
}


static void _gnome_media_keys_unregister_object (gpointer user_data) {
	gpointer* data;
	data = user_data;
	g_signal_handlers_disconnect_by_func (data[0], _dbus_gnome_media_keys_media_player_key_pressed, data);
	g_object_unref (data[0]);
	g_object_unref (data[1]);
	g_free (data[2]);
	g_free (data);
}


static void _rdio_media_key_listener_mediaKeyPressed_gnome_media_keys_media_player_key_pressed (GnomeMediaKeys* _sender, const gchar* application, const gchar* key, gpointer self) {
	rdio_media_key_listener_mediaKeyPressed (self, _sender, application, key);
}


RdioMediaKeyListener* rdio_media_key_listener_construct (GType object_type) {
	RdioMediaKeyListener * self = NULL;
	GnomeMediaKeys* _tmp5_;
	GError * _inner_error_ = NULL;
	self = (RdioMediaKeyListener*) g_object_new (object_type, NULL);
	{
		GnomeMediaKeys* _tmp0_ = NULL;
		GnomeMediaKeys* _tmp1_;
		_tmp0_ = g_initable_new (TYPE_GNOME_MEDIA_KEYS_PROXY, NULL, &_inner_error_, "g-flags", 0, "g-name", "org.gnome.SettingsDaemon", "g-bus-type", G_BUS_TYPE_SESSION, "g-object-path", "/org/gnome/SettingsDaemon/MediaKeys", "g-interface-name", "org.gnome.SettingsDaemon.MediaKeys", NULL);
		_tmp1_ = (GnomeMediaKeys*) _tmp0_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_IO_ERROR) {
				goto __catch5_g_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_object_unref0 (self->priv->media_object);
		self->priv->media_object = _tmp1_;
	}
	goto __finally5;
	__catch5_g_io_error:
	{
		GError* e = NULL;
		FILE* _tmp2_;
		GError* _tmp3_;
		const gchar* _tmp4_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp2_ = stderr;
		_tmp3_ = e;
		_tmp4_ = _tmp3_->message;
		fprintf (_tmp2_, "Mediakeys error: %s\n", _tmp4_);
		_g_error_free0 (e);
	}
	__finally5:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp5_ = self->priv->media_object;
	if (_tmp5_ != NULL) {
		GnomeMediaKeys* _tmp6_;
		_tmp6_ = self->priv->media_object;
		g_signal_connect_object (_tmp6_, "media-player-key-pressed", (GCallback) _rdio_media_key_listener_mediaKeyPressed_gnome_media_keys_media_player_key_pressed, self, 0);
		{
			GnomeMediaKeys* _tmp7_;
			_tmp7_ = self->priv->media_object;
			gnome_media_keys_GrabMediaPlayerKeys (_tmp7_, "rdio", (guint32) 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_IO_ERROR) {
					goto __catch6_g_io_error;
				}
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
		goto __finally6;
		__catch6_g_io_error:
		{
			GError* err = NULL;
			FILE* _tmp8_;
			GError* _tmp9_;
			const gchar* _tmp10_;
			err = _inner_error_;
			_inner_error_ = NULL;
			_tmp8_ = stdout;
			_tmp9_ = err;
			_tmp10_ = _tmp9_->message;
			fprintf (_tmp8_, "Could not grab media player keys: %s\n", _tmp10_);
			_g_error_free0 (err);
		}
		__finally6:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	return self;
}


RdioMediaKeyListener* rdio_media_key_listener_new (void) {
	return rdio_media_key_listener_construct (RDIO_TYPE_MEDIA_KEY_LISTENER);
}


void rdio_media_key_listener_releaseMediaKeys (RdioMediaKeyListener* self) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	{
		GnomeMediaKeys* _tmp0_;
		_tmp0_ = self->priv->media_object;
		gnome_media_keys_ReleaseMediaPlayerKeys (_tmp0_, "rdio", &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_IO_ERROR) {
				goto __catch7_g_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally7;
	__catch7_g_io_error:
	{
		GError* err = NULL;
		FILE* _tmp1_;
		GError* _tmp2_;
		const gchar* _tmp3_;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp1_ = stdout;
		_tmp2_ = err;
		_tmp3_ = _tmp2_->message;
		fprintf (_tmp1_, "Could not release media player keys: %s\n", _tmp3_);
		_g_error_free0 (err);
	}
	__finally7:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void rdio_media_key_listener_mediaKeyPressed (RdioMediaKeyListener* self, GObject* bus, const gchar* application, const gchar* key) {
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (bus != NULL);
	g_return_if_fail (application != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = application;
	if (g_strcmp0 (_tmp0_, "rdio") != 0) {
		return;
	}
	_tmp1_ = key;
	if (g_strcmp0 (_tmp1_, "Previous") == 0) {
		RdioMiddleware* _tmp2_;
		RdioMiddleware* _tmp3_;
		_tmp2_ = rdio_app_get_middleware ();
		_tmp3_ = _tmp2_;
		rdio_middleware_previous (_tmp3_);
	} else {
		const gchar* _tmp4_;
		_tmp4_ = key;
		if (g_strcmp0 (_tmp4_, "Play") == 0) {
			RdioMiddleware* _tmp5_;
			RdioMiddleware* _tmp6_;
			_tmp5_ = rdio_app_get_middleware ();
			_tmp6_ = _tmp5_;
			rdio_middleware_playpause (_tmp6_);
		} else {
			const gchar* _tmp7_;
			_tmp7_ = key;
			if (g_strcmp0 (_tmp7_, "Next") == 0) {
				RdioMiddleware* _tmp8_;
				RdioMiddleware* _tmp9_;
				_tmp8_ = rdio_app_get_middleware ();
				_tmp9_ = _tmp8_;
				rdio_middleware_next (_tmp9_);
			} else {
				const gchar* _tmp10_;
				_tmp10_ = key;
				g_warning ("MediaKeyListener.vala:76: Unused key pressed: %s\n", _tmp10_);
			}
		}
	}
}


static void rdio_media_key_listener_class_init (RdioMediaKeyListenerClass * klass) {
	rdio_media_key_listener_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (RdioMediaKeyListenerPrivate));
	G_OBJECT_CLASS (klass)->finalize = rdio_media_key_listener_finalize;
}


static void rdio_media_key_listener_instance_init (RdioMediaKeyListener * self) {
	self->priv = RDIO_MEDIA_KEY_LISTENER_GET_PRIVATE (self);
}


static void rdio_media_key_listener_finalize (GObject* obj) {
	RdioMediaKeyListener * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, RDIO_TYPE_MEDIA_KEY_LISTENER, RdioMediaKeyListener);
	_g_object_unref0 (self->priv->media_object);
	G_OBJECT_CLASS (rdio_media_key_listener_parent_class)->finalize (obj);
}


GType rdio_media_key_listener_get_type (void) {
	static volatile gsize rdio_media_key_listener_type_id__volatile = 0;
	if (g_once_init_enter (&rdio_media_key_listener_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (RdioMediaKeyListenerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) rdio_media_key_listener_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RdioMediaKeyListener), 0, (GInstanceInitFunc) rdio_media_key_listener_instance_init, NULL };
		GType rdio_media_key_listener_type_id;
		rdio_media_key_listener_type_id = g_type_register_static (G_TYPE_OBJECT, "RdioMediaKeyListener", &g_define_type_info, 0);
		g_once_init_leave (&rdio_media_key_listener_type_id__volatile, rdio_media_key_listener_type_id);
	}
	return rdio_media_key_listener_type_id__volatile;
}



