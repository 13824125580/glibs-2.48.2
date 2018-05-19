/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description: test 
 *
 *        Version:  1.0
 *        Created:  2018年05月18日 20时57分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<glib-object.h>  
  
#define SOME_OBJECT_TYPE        (some_object_get_type())  
#define SOME_OBJECT(obj)        (G_TYPE_CHECK_INSTANCE_CAST((obj), SOME_OBJECT_TYPE, SomeObject))  
#define SOME_IS_OBJECT(obj)     (GTYPE_CHECK_TYPE((obj), SOME_OBJECT_TYPE))  
#define SOME_OBJECT_CLASS(c)        (G_TYPE_CHECK_CLASS_CAST((c), SOME_OBJECT_TYPE,SomeObjectClass))  
#define SOME_IS_OBJECT_CLASS(c)     (G_TYPE_CHECK_CLASS_TYPE((c), SOME_OBJECT_TYPE))  
#define SOME_OBJECT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), SOME_OBJECT_TYPE, SomeObjectClass))  
  
typedef struct _SomeObject SomeObject;  
struct _SomeObject {  
    GObject parent_obj;  
};  
  
typedef struct _SomeObjectClass SomeObjectClass;  
struct _SomeObjectClass {  
    GObjectClass parent_class;  
};  
  
G_DEFINE_TYPE (SomeObject, some_object, G_TYPE_OBJECT)  
  
void some_object_dispose(GObject *gobject)  
{  
    SomeObject *slef = SOME_OBJECT(gobject);  
    g_print("-- %s # %i\n",__func__, __LINE__);  
    G_OBJECT_CLASS(some_object_parent_class)->dispose(gobject);  
}  
  
void some_object_finalize(GObject *gobject)  
{  
    SomeObject *self = SOME_OBJECT(gobject);  
    g_print("-- %s # %i\n",__func__, __LINE__);  
    G_OBJECT_CLASS(some_object_parent_class)->finalize(gobject);  
}  
  
static void some_object_class_init(SomeObjectClass* g_class)  
{  
    GObjectClass *this_class = G_OBJECT_CLASS(g_class);  
    GParamSpec *spec;  
  
    g_print("-- %s # %i\n",__func__, __LINE__);  
    this_class->dispose = &some_object_dispose;  
    this_class->finalize = &some_object_finalize;  
}  
  
void some_object_init(SomeObject *self)  
{  
    g_print("-- %s # %i\n",__func__, __LINE__);  
    g_object_set(G_OBJECT(self),NULL,0,NULL,NULL,NULL);  
}  
  
int main()  
{  
    g_print("****init the type system****\n");  
#if !GLIB_CHECK_VERSION(2,35,0)
    g_type_init();  
#endif
    g_print("****init type system OK ****\n");  
    SomeObject *testobj = g_object_new(SOME_OBJECT_TYPE, NULL);;  
    g_object_unref(testobj);  
    g_print("****finish GObject Demo ****\n");  
    return 0;  
}  
