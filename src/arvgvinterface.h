#ifndef ARV_GV_INTERFACE_H
#define ARV_GV_INTERFACE_H

#include <arv.h>
#include <arvgvcp.h>
#include <arvinterface.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define ARV_GV_INTERFACE_DISCOVERY_TIMEOUT_MS	1000
#define ARV_GV_INTERFACE_SOCKET_BUFFER_SIZE	1024

#define ARV_TYPE_GV_INTERFACE             (arv_gv_interface_get_type ())
#define ARV_GV_INTERFACE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), ARV_TYPE_GV_INTERFACE, ArvGvInterface))
#define ARV_GV_INTERFACE_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), ARV_TYPE_GV_INTERFACE, ArvGvInterfaceClass))
#define ARV_IS_GV_INTERFACE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ARV_TYPE_GV_INTERFACE))
#define ARV_IS_GV_INTERFACE_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), ARV_TYPE_GV_INTERFACE))
#define ARV_GV_INTERFACE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), ARV_TYPE_GV_INTERFACE, ArvGvInterfaceClass))

typedef struct _ArvGvInterfaceClass ArvGvInterfaceClass;

struct _ArvGvInterface {
	ArvInterface	interface;

	unsigned int n_discover_infos;
	GSList *discover_infos_list;

	GHashTable *devices;
};

struct _ArvGvInterfaceClass {
	ArvInterfaceClass parent_class;
};

GType arv_gv_interface_get_type (void);

ArvInterface * 		arv_gv_interface_get_instance 		(void);

ArvDevice * 		arv_gv_interface_get_device_by_address 	(ArvGvInterface *gv_interface, const char *address);

G_END_DECLS

#endif
