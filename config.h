/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* alt-tab configuration */
static const unsigned int tabModKey 		= 0x40;	/* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey 		= 0x17;	/* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY 			= 1;	/* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX 			= 1;	/* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab 			= 600;	/* tab menu width */
static const unsigned int maxHTab 			= 200;	/* tab menu height */

/* appearance */
static unsigned int borderpx  = 2;        /* border pixel of windows */
static unsigned int gappih    = 15;       /* horiz inner gap between windows */
static unsigned int gappiv    = 15;       /* vert inner gap between windows */
static unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const unsigned int snap= 10;       /* snap pixel */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 6;   /* systray spacing */
static const unsigned int systrayiconsize = 26;	/* systray icon size in px */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
char *fonts[]          = { "Hack Nerd Font Mono:style=Regular:pixelsize=22:autohint=true:antialias=true" };
static char normbgcolor[]           = "#32302F";
static char normbordercolor[]       = "#32302F";
static char normfgcolor[]           = "#709990";
static char selfgcolor[]            = "#32302F";
static char selbordercolor[]        = "#779B72";
static char selbgcolor[]            = "#709990";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
};

/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
	{ TERMCLASS,  NULL,       NULL,       	    0,            0,           1,         0,        -1 },
	{ NULL,       NULL,       "Event Tester",   0,            0,           0,         1,        -1 },
	{ TERMCLASS, "bg",        NULL,       	    1<<4,         0,           1,         0,        -1 },
	{ TERMCLASS, "spterm",    NULL,       	    SPTAG(0),     1,           1,         0,        -1 },
	{ TERMCLASS, "spcalc",    NULL,       	    SPTAG(1),     1,           1,         0,        -1 },
	{ "leagueclientux.exe", NULL, "League of Legends", 1<<3,  1,           0,         0,        -1 },
	{ "league of legends.exe", NULL, "League of Legends (TM) Client", 1<<3, 0, 0, 	  0, 	    -1 },
	{ "steam",    NULL, 	  "Steam", 	    	1<<4,     	  0,           0,         0,        -1 },
	{ "lutris",   NULL, 	  "Lutris",	    	1<<4,	  	  0,	       0,	  	  0,	    -1 },
	{ "Lutris",   NULL, 	  "Lutris",	    	1<<4,         0,	       0,	  	  0,	    -1 },
	{ "battle.net.exe", NULL, "Battle.net",	    0,		  	  0,	       0,	  	  0,	    -1 },
	{ "d2r.exe",  NULL,	  	  "Diablo II: Resurrected", 0, 	  0,	       0,	  	  0,	    -1 },
	{ "Slay the Spire", NULL, "Slay the Spire", 1<<3,	  	  0,	       0,	  	  0,	    -1 },
	{ "zoom", 	  NULL, 	  "Zoom Meeting", 	1<<4,	  	  0,	       0,	  	  0,	    -1 },
	{ "zoom ", 	  NULL, 	  "Zoom Meeting", 	1<<4,	  	  0,	       0,	  	  0,	    -1 },
	{ "zoom", 	  NULL, 	  "Zoom - Free account", 1<<4,	  0,	       0,	  	  0,	    -1 },
	{ "zoom ", 	  NULL, 	  "Zoom - Free account", 1<<4,	  0,	       0,	  	  0,	    -1 },
	{ "zoom", 	  NULL, 	  "Zoom Cloud Meetings", 1<<4,	  	  0,	       0,	  	  0,	    -1 },
	{ "zoom ", 	  NULL, 	  "Zoom Cloud Meetings", 1<<4,	  	  0,	       0,	  	  0,	    -1 },
	{ "zoom", 	  NULL, 	  "Zoom", 			1<<3,	  	  0,	       0,	  	  0,	    -1 },
	{ "zoom ", 	  NULL, 	  "Zoom", 			1<<3,	  	  0,	       0,	  	  0,	    -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	/*{ "TTT",	bstack },*/		/* Master on top, slaves on bottom */

	/*{ "[@]",	spiral },*/		/* Fibonacci spiral */
	/*{ "[\\]",	dwindle },*/		/* Decreasing in size right and leftward */

	/*{ "[D]",	deck },*/			/* Master on left, slaves in monocle-like mode on right */
	/*{ "[M]",	monocle },*/		/* All windows on top of eachother */

	/*{ "|M|",	centeredmaster },*/		/* Master in middle, slaves on sides */
	/*{ ">M>",	centeredfloatingmaster },*/	/* Same but master floats */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ ControlMask,                   KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/*{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/*{ MOD, XK_z,     ACTION##stack, {.i = -1 } },*/

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *librewolfcmd[] = { "/bin/librewolf", NULL };
static const char *pcmanfmcmd[] = { "/usr/bin/pcmanfm", NULL };
static const char *lutriscmd[] = { "/usr/bin/python3", "/usr/bin/lutris", NULL };
static const char *leaguecmd[] = { "gamemoderun", "leagueoflegends", "start", NULL };
static const char *medplaypausecmd[] = { "playerctl", "play-pause", NULL };
static const char *mednextcmd[] = { "playerctl", "next", NULL };
static const char *medprevcmd[] = { "playerctl", "previous", NULL };
static const char *medstopcmd[] = {"playerctl", "stop", NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",		STRING,	&normbordercolor },
		{ "color12",	STRING,	&selbordercolor },
		{ "color0",		STRING,	&normbgcolor },
		{ "color4",		STRING,	&normfgcolor },
		{ "color0",		STRING,	&selfgcolor },
		{ "color4",		STRING,	&selbgcolor },
		{ "borderpx",	INTEGER, &borderpx },
		{ "snap",		INTEGER, &snap },
		{ "showbar",	INTEGER, &showbar },
		{ "topbar",		INTEGER, &topbar },
		{ "nmaster",	INTEGER, &nmaster },
		{ "resizehints", INTEGER, &resizehints },
		{ "mfact",		FLOAT,	&mfact },
		{ "gappih",		INTEGER, &gappih },
		{ "gappiv",		INTEGER, &gappiv },
		{ "gappoh",		INTEGER, &gappoh },
		{ "gappov",		INTEGER, &gappov },
		{ "swallowfloating",	INTEGER, &swallowfloating },
		{ "smartgaps",		INTEGER, &smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	/* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
	{ MODKEY,			XK_grave,	spawn,	SHCMD("dmenuunicode") },
	/* { MODKEY|ShiftMask,		XK_grave,	togglescratch,	SHCMD("") }, */
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	/*TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)*/
	/* { MODKEY,			XK_q,		view,		{0} }, */
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,			XK_minus,	spawn,		SHCMD("cmus-remote --vol -10%") },
	{ MODKEY,			XK_equal,	spawn,		SHCMD("cmus-remote --vol +10%") },
	{ MODKEY,			XK_F12,		locktagsfor,	{.ui = 7200 } },
	{ MODKEY,			XK_F11,		locktagsfor,	{.ui = 0 } },
	/*{ MODKEY,			XK_BackSpace,	spawn,		SHCMD("sysact") },*/
	/*{ MODKEY|ShiftMask,		XK_BackSpace,	spawn,		SHCMD("sysact") },*/

	{ MODKEY,			XK_v,		view,		{0} },
	{ MODKEY,			XK_Tab,		altTabStart,	{0} },
	{ MODKEY|ShiftMask,		XK_q,		killclient,	{0} },
	{ Mod4Mask|ShiftMask,		XK_q,		quit,		{0} },
	/*{ MODKEY,			XK_w,		spawn,		SHCMD("$BROWSER") },*/
	/*{ MODKEY|ShiftMask,		XK_w,		spawn,		SHCMD(TERMINAL " -e sudo nmtui") },*/
	/*{ MODKEY,			XK_e,		spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") },*/
	{ Mod4Mask,			XK_e,		spawn,		{.v = pcmanfmcmd } },
	/*{ MODKEY,			XK_r,		spawn,		SHCMD(TERMINAL " -e lfub") },*/
	/*{ MODKEY|ShiftMask,		XK_r,		spawn,		SHCMD(TERMINAL " -e htop") },*/
	/*{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[1]} },*/ /* bstack */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[0]} }, /* tile */
	/*{ MODKEY,			XK_y,		setlayout,	{.v = &layouts[2]} },*/ /* spiral */
	/*{ MODKEY|ShiftMask,		XK_y,		setlayout,	{.v = &layouts[3]} },*/ /* dwindle */
	/*{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[4]} },*/ /* deck */
	/*{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[5]} },*/ /* monocle */
	/*{ MODKEY,			XK_i,		setlayout,	{.v = &layouts[6]} },*/ /* centeredmaster */
	/*{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[7]} },*/ /* centeredfloatingmaster */
	/*{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_p,			spawn,		SHCMD("mpc toggle") },
	{ MODKEY|ShiftMask,		XK_p,			spawn,		SHCMD("mpc pause ; pauseallmpv") },
	{ MODKEY,			XK_bracketleft,		spawn,		SHCMD("mpc seek -10") },
	{ MODKEY|ShiftMask,		XK_bracketleft,		spawn,		SHCMD("mpc seek -60") },
	{ MODKEY,			XK_bracketright,	spawn,		SHCMD("mpc seek +10") },
	{ MODKEY|ShiftMask,		XK_bracketright,	spawn,		SHCMD("mpc seek +60") },
	{ MODKEY,			XK_backslash,		view,		{0} },
	{ MODKEY|ShiftMask,		XK_backslash,		spawn,		SHCMD("") }, */

	/*{ MODKEY,			XK_a,		togglegaps,	{0} },*/
	/*{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },*/
	{ Mod4Mask,			XK_s,		spawn,		SHCMD("steam-runtime") },
	/*{ MODKEY|ShiftMask,		XK_s,		spawn,		SHCMD("systemctl suspend") },*/
	{ Mod4Mask,			XK_Return,	spawn,          SHCMD("dmenu_run") },
	/*{ MODKEY|ShiftMask,		XK_d,		spawn,		SHCMD("passmenu") },*/
	/*{ MODKEY,			XK_f,		togglefullscr,	{0} },*/
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[1]} },
	/*{ MODKEY,			XK_g,		shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_g,		shifttag,	{ .i = -1 } },*/
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.05} },
	{ MODKEY,			XK_l,		setmfact,	{.f = +0.05} },
	/* J and K are automatically bound above in STACKEYS */
	{ Mod4Mask,			XK_l,		spawn,      	{.v = lutriscmd } },
	{ MODKEY|ShiftMask,		XK_l,		spawn,      	{.v = leaguecmd } },
	/*{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	{ MODKEY|ShiftMask,		XK_semicolon,	shifttag,	{ .i = 1 } },
	{ MODKEY,			XK_apostrophe,	togglescratch,	{.ui = 1} },*/
	/* { MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, */
	/*{ MODKEY|ShiftMask,		XK_apostrophe,	togglesmartgaps,	{0} },*/
	{ Mod4Mask,			XK_t,		spawn,		{.v = termcmd } },
	{ Mod4Mask,			XK_f,		spawn,		{.v = librewolfcmd } },
	{ MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0} },

	/*{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
	{ MODKEY|ShiftMask,		XK_z,		spawn,		SHCMD("") },
	{ MODKEY,			XK_x,		incrgaps,	{.i = -3 } },*/
	/* { MODKEY|ShiftMask,		XK_x,		spawn,		SHCMD("") }, */
	/* { MODKEY,			XK_c,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_c,		spawn,		SHCMD("") }, */
	/* V is automatically bound above in STACKKEYS */
	{ MODKEY|ShiftMask,		XK_b,		togglebar,	{0} },
	/* { MODKEY|ShiftMask,		XK_b,		spawn,		SHCMD("") }, */
	/*{ MODKEY,			XK_n,		spawn,		SHCMD(TERMINAL " -e nvim -c VimwikiIndex") },
	{ MODKEY|ShiftMask,		XK_n,		spawn,		SHCMD(TERMINAL " -e newsboat; pkill -RTMIN+6 dwmblocks") },*/
	{ Mod4Mask,			XK_m,		spawn,		{.v = mobalyticscmd } },
	/*{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_comma,	spawn,		SHCMD("mpc prev") },
	{ MODKEY|ShiftMask,		XK_comma,	spawn,		SHCMD("mpc seek 0%") },
	{ MODKEY,			XK_period,	spawn,		SHCMD("mpc next") },
	{ MODKEY|ShiftMask,		XK_period,	spawn,		SHCMD("mpc repeat") },

	{ MODKEY,			XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },

	{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },
	{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = +1 } },
	{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },
	{ MODKEY,			XK_Insert,	spawn,		SHCMD("xdotool type $(grep -v '^#' ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") },

	{ MODKEY,			XK_F1,		spawn,		SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
	{ MODKEY,			XK_F2,		spawn,		SHCMD("tutorialvids") },
	{ MODKEY,			XK_F3,		spawn,		SHCMD("displayselect") },
	{ MODKEY,			XK_F4,		spawn,		SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_F5,		xrdb,		{.v = NULL } },
	{ MODKEY,			XK_F6,		spawn,		SHCMD("torwrap") },
	{ MODKEY,			XK_F7,		spawn,		SHCMD("td-toggle") },
	{ MODKEY,			XK_F8,		spawn,		SHCMD("mw -Y") },
	{ MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") },
	{ MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") },
	{ MODKEY,			XK_F11,		spawn,		SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
	{ MODKEY,			XK_F12,		spawn,		SHCMD("remaps & notify-send \\\"⌨️ Keyboard remapping...\\\" \\\"Re-running keyboard defaults for any newly plugged-in keyboards.\\\"") },
	{ MODKEY,			XK_Tab,		zoom,		{0} },*/
	{ MODKEY|ShiftMask,		XK_space,	togglealwaysontop,	{0} },

	{ 0,				XK_Print,	spawn,		SHCMD("gnome-screenshot -f ~/misc/screenshots/$(date +%F_%T).png") },
	{ MODKEY,			XK_Print,	spawn,		SHCMD("gnome-screenshot -a -f ~/misc/screenshots/$(date +%F_%T).png") },
	/*{ MODKEY,			XK_Print,	spawn,		SHCMD("dmenurecord") },
	{ MODKEY|ShiftMask,		XK_Print,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Delete,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Scroll_Lock,	spawn,		SHCMD("killall screenkey || screenkey &") },*/

	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,		spawn,		{.v = medprevcmd } },
	{ 0, XF86XK_AudioNext,		spawn,		{.v = mednextcmd } },
	{ 0, XF86XK_AudioPause,		spawn,		{.v = medplaypausecmd } },
	{ 0, XF86XK_AudioPlay,		spawn,		{.v = medplaypausecmd } },
	{ 0, XF86XK_AudioStop,		spawn,		{.v = medstopcmd } },
	/*{ 0, XF86XK_AudioRewind,	spawn,		SHCMD("cmus-remote --seek -5") },
	{ 0, XF86XK_AudioForward,	spawn,		SHCMD("cmus-remote --seek +5") },
	{ 0, XF86XK_AudioMedia,		spawn,		SHCMD(TERMINAL " -e ncmpcpp") },*/
	{ 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	/*{ 0, XF86XK_PowerOff,		spawn,		SHCMD("sysact") },
	{ 0, XF86XK_Calculator,		spawn,		SHCMD(TERMINAL " -e bc -l") },
	{ 0, XF86XK_Sleep,		spawn,		SHCMD("sudo -A zzz") },
	{ 0, XF86XK_WWW,		spawn,		SHCMD("$BROWSER") },
	{ 0, XF86XK_DOS,		spawn,		SHCMD(TERMINAL) },
	{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0, XF86XK_TaskPane,		spawn,		SHCMD(TERMINAL " -e htop") },
	{ 0, XF86XK_Mail,		spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	{ 0, XF86XK_MyComputer,		spawn,		SHCMD(TERMINAL " -e lfub /") },
	{ 0, XF86XK_Battery,		spawn,		SHCMD("") },
	{ 0, XF86XK_Launch1,		spawn,		SHCMD("xset dpms force off") },
	{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,	spawn,		SHCMD("synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOn,		spawn,		SHCMD("synclient TouchpadOff=0") },*/
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 15") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 15") },

	/* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
	/* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	/*{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },*/
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	/*{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },*/
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};
