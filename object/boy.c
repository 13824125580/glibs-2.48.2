/* boy.c */
#include "boy.h"
#include <glib.h>

enum { BOY_BORN, LAST_SIGNAL };
static gint boy_signals[LAST_SIGNAL] = { 0 };

static void boy_cry (void);
static void boy_born(void);

static void boy_init(Boy *boy);
static void boy_class_init(BoyClass *boyclass);
static gint boy_private_offset;
static gpointer boy_parent_class = NULL; 


void send_boy_signals(Boy  *pbase, int i)
{
	g_signal_emit(pbase, boy_signals[BOY_BORN], 0, i);
}

static void boy_class_intern_init (gpointer klass)
{                          
	boy_parent_class = g_type_class_peek_parent (klass);
	if (boy_private_offset != 0)
		g_type_class_adjust_private_offset (klass, &boy_private_offset);
	boy_class_init ((BoyClass*) klass);
}

GType boy_get_type(void)
{
	static volatile gsize g_define_type_id__volatile = 0;

	if (g_once_init_enter (&g_define_type_id__volatile))
	{
		GType boy_type = 0;
		static const GTypeInfo boy_info = {
			sizeof(BoyClass),
			NULL,NULL,
			(GClassInitFunc)boy_class_intern_init,
			NULL,NULL,
			sizeof(Boy),
			0,
			(GInstanceInitFunc)boy_init
		};
		boy_type = g_type_register_static(
			   G_TYPE_OBJECT,"Boy",&boy_info,0);

		g_once_init_leave (&g_define_type_id__volatile, boy_type);
	}
	return g_define_type_id__volatile;
}

static void boy_init(Boy *boy)
{
	boy->age = 0;
	boy->name = "none";
	boy->cry = boy_cry;
}

static void boy_class_init(BoyClass *boyclass)
{
    	GObjectClass *gobject_class;

	gobject_class = G_OBJECT_CLASS (boyclass);
	boyclass->boy_born = boy_born;
	boy_signals[BOY_BORN] = g_signal_new("boy_born",
				BOY_TYPE,
				G_SIGNAL_RUN_FIRST,
				G_STRUCT_OFFSET(BoyClass,boy_born),
				NULL,NULL,
				g_cclosure_marshal_VOID__VOID,
				G_TYPE_NONE, 0, NULL);
}

Boy *boy_new(void)
{
	Boy *boy;
	boy = g_object_new(BOY_TYPE, NULL);
	g_signal_emit(boy,boy_signals[BOY_BORN],0);
	return boy;
}

int boy_get_age(Boy *boy)
{
	return boy->age;
}

void boy_set_age(Boy *boy, int age)
{
	boy->age = age;
}

char *boy_get_name(Boy *boy)
{
	return boy->name;
}

void boy_set_name(Boy *boy, char *name)
{
	boy->name = name;
}

Boy*  boy_new_with_name(gchar *name)
{
	Boy* boy;
	boy = boy_new();
	boy_set_name(boy, name);
	return boy;
}

Boy*  boy_new_with_age(gint age)
{
	Boy* boy;
	boy = boy_new();
	boy_set_age(boy, age);
	return boy;
}

Boy *boy_new_with_name_and_age(gchar *name, gint age)
{
	Boy *boy;
	boy = boy_new();
	boy_set_name(boy,name);
	boy_set_age(boy,age);
	return boy;
}

static void boy_cry (void)
{
	g_print("The Boy is crying ......\n");
}

static void boy_born(void)
{
	g_print("Message : A boy was born .\n");
}

void  boy_info(Boy *boy)
{
	g_print("The Boy name is %s\n", boy->name);
	g_print("The Boy age is %d\n", boy->age);
}
