/*
 * $Id$
 *
 * Copyright (c) 2010, Juniper Networks, Inc.
 * All rights reserved.
 */

/*
 * Input/output read/write/print functions
 */

/*
 * If we hit any invalid xmlChar (such as ^T), we need to encode this into
 * Unicode XML format "&#xYYYY;" in the Private area of E000-F8FF.  For
 * instance, ^T (0x14) becomes &#xE014;  This ensures we don't break XML
 * parsing and we can read these control characters back in.
 */
#ifndef SLAX_UTF8_CNTRL_BASE
#define SLAX_UTF8_CNTRL_BASE 0xe000
#define SLAX_UTF8_CNTRL_END 0xe100
#define SLAX_UTF8_CNTRL "&#x%04x;"
#define SLAX_UTF8_CNTRL_SIZE 8
#define SLAX_UTF8_CNTRL_BYTES 3
#endif /* SLAX_UTF8_CNTRL_BASE */

/**
 * Use the input callback to get data
 * @prompt the prompt to be displayed
 */
char *
slaxInput (const char *prompt, unsigned flags);

/**
 * Use the callback to output a string
 * @fmt printf-style format string
 */
void
#ifdef HAVE_PRINTFLIKE
__printflike(1, 2)
#endif /* HAVE_PRINTFLIKE */
slaxOutput (const char *fmt, ...);

/**
 * Output a node
 */
void
slaxOutputNode (xmlNodePtr);

/**
 * Print the given nodeset. First we print the nodeset in a temp file.
 * Then read that file and send the the line to mgd one by one.
 */
void
slaxOutputNodeset (xmlNodeSetPtr nodeset);

/*
 * Simple trace function that tosses messages to stderr if slaxDebug
 * has been set to non-zero.
 */
void
slaxLog (const char *fmt, ...);
