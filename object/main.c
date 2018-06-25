#include <glib.h>
#include "boy.h"
#include "man.h"

void send_boy_signals(Boy  *pbase, int i);


static void boy_born_callback_connect(Boy *pbase,int i,gpointer user_data)
{
	g_print("%s line %d\n", __func__, __LINE__);
}
int main(int argc, char *argv[])
{
	Man *green, *brown;	

#if !GLIB_CHECK_VERSION(2,35,0)
	g_type_init();
#endif

/*
 *        tom = boy_new_with_name("Tom");
 *
 *        g_signal_connect(G_OBJECT(tom), "boy_born", G_CALLBACK(boy_born_callback_connect),NULL);
 *        send_boy_signals(tom, 1);
 *        tom->cry();
 *        boy_info(tom);
 *
 *        peter = boy_new_with_name_and_age("Peter", 10);
 *        peter->cry();
 *        boy_info(peter);
 */

	green = man_new();
	boy_set_name(BOY(green), "Green");
	boy_set_age(BOY(green), 28);
	man_set_job(green, "Doctor");
	green->bye();
	man_info(green);

	brown = man_new_with_name_age_and_job("Brown", 30, "Teacher");
	brown->bye();
	man_info(brown);
}

