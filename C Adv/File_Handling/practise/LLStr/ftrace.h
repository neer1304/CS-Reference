#define NO_TRACE 0
#define BRIEF_TRACE 1
#define DETAILED_TRACE 2

int g_set_trace_level=DETAILED_TRACE;

#ifdef TRACE
#define XXX_TRACE(level,message) if(g_set_trace_level>=level) fprintf message
#else
#define XXX_TRACE(level,message)
#endif


