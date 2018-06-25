/* man.c */
#include "man.h"

static void man_bye(void);

static void man_init(Man *man);
static void man_class_init(ManClass *man);
static gint man_private_offset;
static gpointer man_parent_class = NULL; 

static void man_class_intern_init (gpointer klass)
{                          
	man_parent_class = g_type_class_peek_parent (klass);
	if (man_private_offset != 0)
		g_type_class_adjust_private_offset (klass, &man_private_offset);
	man_class_init ((ManClass*) klass);
}

GType man_get_type(void)
{
	static volatile gsize g_define_type_id__volatile = 0;

	if (g_once_init_enter (&g_define_type_id__volatile))
	{
		GType man_type = 0;
		static const GTypeInfo man_info = {
			sizeof(ManClass),
			NULL, NULL,
			(GClassInitFunc)man_class_intern_init,
			NULL, NULL,
			sizeof(Man),
			0,
			(GInstanceInitFunc)man_init
		};
		man_type = g_type_register_static(BOY_TYPE, "Man", &man_info, 0);
		g_once_init_leave (&g_define_type_id__volatile, man_type);
	}
	return g_define_type_id__volatile;
}

static void man_init(Man *man)
{
	man->job = "none";
	man->bye = man_bye;
}

static void man_class_init(ManClass *manclass)
{
    	GObjectClass *gobject_class;
	BoyClass *boyclass;

	gobject_class = G_OBJECT_CLASS (manclass);
	boyclass = BOY_CLASS(manclass);
}

Man*  man_new(void)
{
	Man *man;
	man = g_object_new(MAN_TYPE, 0);
	return man;
}

gchar* man_get_gob(Man *man)
{
	return man->job;
}

void  man_set_job(Man *man, gchar *job)
{
	man->job = job;
}

Man*  man_new_with_name_age_and_job(gchar *name, gint age, gchar *job)
{
	Man *man;
	man = man_new();
	boy_set_name(BOY(man), name);
	boy_set_age(BOY(man), age);
	man_set_job(man, job);
	return man;
}

static void man_bye(void)
{
	g_print("Goodbye everyone !\n");
}

void man_info(Man *man)
{
	g_print("the man name is %s\n", BOY(man)->name);
	g_print("the man age is %d\n", BOY(man)->age);
	g_print("the man job is %s\n", man->job);
}


