#include<stdio.h>


typedef struct callbacks {
	void (*on_incoming_call) ();
	void (*on_ring_timer_expiry) ();
	
} cb_t;

void event_incoming_call();
void event_timer_expired();

main()
{
  cb_t call_back;

  /* registration */
   call_back.on_incoming_call = &event_incoming_call;
   call_back.on_ring_timer_expiry = &event_timer_expired;

/* lots of code... */


/* event handling ... normally via FSM */
   /* if there is an incoming call... */
   call_back.on_incoming_call();

   /* if there timeout occurs and noone picks up the phone */
   call_back.on_ring_timer_expiry();
    
}


void event_incoming_call ()
{
  printf("\nalert for event");
}

void event_timer_expired ()
{
  printf("\nalert for timer expiry\n");

}

