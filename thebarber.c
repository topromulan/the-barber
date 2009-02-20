#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>

#include <X11/Xaw/Command.h>

#define callbackfn(xray) void xray (Widget w, XtPointer client, XtPointer call) 

callbackfn( barber_callback );

char *globaluselesspointer;

int main(int argc, char **argv) {

	/* items referred to by these names vary in function main */
	Widget toplevel, barber_button;
	auto int user_error=0;
	/*                                                        */

	/* user error check */
	if(argc < 3) {  
		/* the user had a problem entering the command line */
		printf("Problem running the barber. Recompile. Running anyway.");
		user_error = 1;
	}
	

	/*
	 mental note: 	argv[1] is button blaspheme
			argv[2] is system command
	*/

	
	toplevel = XtInitialize(
			argv[0],
			"thebarber",
			NULL,
			0,
			&argc,
			argv
			);

	if( user_error == 0 ) {
		/* assume the user knew what he was entering */
 		globaluselesspointer = argv[2];
	} else {
		/* assume user wants to run more copies of the barber */
		globaluselesspointer = argv[0]; 
	}

	barber_button = XtVaCreateManagedWidget (
			"I AM THE BARBER",
			commandWidgetClass,
			toplevel,
			XtNlabel, argv[1],
			NULL,	
			0
			);


	/* end of useless definitions */

	XtAddCallback(barber_button, XtNcallback, barber_callback, NULL);

	XtRealizeWidget(toplevel);

	XtMainLoop();

}

callbackfn( barber_callback )
{
	system(globaluselesspointer); /* god damn you! */
}
