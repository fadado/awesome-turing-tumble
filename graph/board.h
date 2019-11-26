/*
 * Turing Tumble graphs
 */

#define $false   0
#define $true    1

/*
 * Parameters
 */

/* Show graph label? */
#if !defined(ShowGraphLabel)
#   define ShowGraphLabel $true
#endif

/* Show objective description? */
#if !defined(ShowObjective)
#   define ShowObjective $true
#endif

/* Show blue/red up lines? */
#if !defined(ShowBackBoardEdges)
#   define ShowBackBoardEdges $true
#endif

/*
 * Fonts, colors, etc.
 */
#define FONTNAME        Helvetica
#define FONTNAME_BOLD   "Helvetica-Bold"
#define FONTCOLOR       black

#define BITCOLOR        deepskyblue
#define BITSIZE         20

#define BITRIGHT        ">"
#define BITLEFT         "<"
#define BITUNDEF        "^"

#define GBITCOLOR       dodgerblue3
#define GLINECOLOR      crimson

#define GBITRIGHT       "}"
#define GBITLEFT        "{"
#define GBITUNDEF       "^"

/*
 * Styles
 */
#define NODE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=12             \
    shape=circle            \
    fixedsize=true          \

#define EDGE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=10             \

#define GRAPH_STYLE         \
    fontname=FONTNAME_BOLD  \
    fontcolor=FONTCOLOR     \
    fontsize=12             \
    labelloc=t              \

#define START_STYLE         \
    shape=point             \
    width=0.11              \

#define OBJECTIVE_STYLE     \
    shape=plaintext         \
    fontsize=10             \
    fontname=Times          \
    fixedsize=false         \

#define BIT_STYLE           \
    shape=diamond           \
    fontcolor=BITCOLOR      \
    fontsize=BITSIZE        \

#define INTERCEPTOR_STYLE   \
    shape=doublecircle      \
    width=0.3               \
    label=""                \

#define GEAR_BIT_STYLE      \
    shape=diamond           \
    fontcolor=GBITCOLOR     \
    fontsize=BITSIZE        \
    style=bold              \

#define GEAR_LINE_STYLE     \
    dir=none                \
    style="bold,solid"      \
    color=GLINECOLOR        \

/*
 * Game Board
 */
#define GAME_BOARD_NODES        \
    start [ START_STYLE ]       \
    B_top [                     \
        label="B"               \
        fontcolor=blue          \
    ]                           \
    B_bot [                     \
        label="%"               \
        fontcolor=blue          \
    ]                           \
    R_top [                     \
        label="R"               \
        fontcolor=red           \
    ]                           \
    R_bot [                     \
        label="%"               \
        fontcolor=red           \
    ]                           \
    {rank=same; B_top, R_top}   \
    {rank=same; B_bot, R_bot}   \

#define BOARD_BACK_BLUE_EDGE    \
    B_bot:w -> B_top:w [        \
        style=dotted            \
        dir=none                \
        color=blue              \
    ]

#define BOARD_BACK_RED_EDGE     \
    R_bot:e -> R_top:e [        \
        style=dotted            \
        dir=none                \
        color=red               \
    ]                           \

#if ShowBackBoardEdges

#define GAME_BOARD_EDGES    \
    BOARD_BACK_BLUE_EDGE    \
    BOARD_BACK_RED_EDGE     \
    B_bot -> R_bot [style=invis]

#else

#define GAME_BOARD_EDGES    \
    B_bot -> R_bot [style=invis]

#endif

/*
 * Labels
 */
#define $text(...)  < <TABLE BORDER="0" CELLPADDING="0" CELLSPACING="0">__VA_ARGS__</TABLE> >
#define $line(...)  <TR><TD ALIGN="left">__VA_ARGS__</TD></TR>

#define $xlabel(s)   xlabel=< <FONT POINT-SIZE="10">s</FONT> >

// vim:ai:sw=4:ts=4:et:syntax=dot
