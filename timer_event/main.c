#include <stdlib.h>
#include <stdio.h>
#include <event.h>
#include <time.h>
#define MAX_EVENT_TIMERS 5000

static struct event *ev_timers_gl_array[5000]; 
static struct event_base *ev_base;

static int find_free_event(){
    int free_event =0;
    for (;free_event < MAX_EVENT_TIMERS; ++free_event)
    {
        if(!ev_timers_gl_array[free_event]){
            break;
        }
    }
    
    return free_event;
    
}
static struct event *ev_timers_gl_array[MAX_EVENT_TIMERS] = {0};
static int find_free_event_timer(){

    int free_event_id =0;
    for (;free_event_id < MAX_EVENT_TIMERS; ++free_event_id)
    {
        if(!ev_timers_gl_array[free_event_id]){
            break;
        }
    }

    return free_event_id;
}
static void call_back(int fd, short wich, void * args ){
        
      printf(" Event called  %d\n", find_free_event());
      int free_event =find_free_event();
        printf("%d\n", free_event);
      if(free_event <MAX_EVENT_TIMERS){
         ev_timers_gl_array[free_event] = event_new(ev_base, 0, EV_PERSIST, call_back,&free_event);
      }
     
}
int main(){
    struct event_base *ev_base;
    ev_base = event_base_new();
  
    int counter = 0;
    if(ev_base==NULL){
        printf("Error. unable to allocate memory for event base\n");
        return 0;
    }
    int free_event = find_free_event();
    printf("%d free event\n", free_event);
    ev_timers_gl_array[free_event] = event_new(ev_base, 0, EV_PERSIST, call_back, ev_timers_gl_array[free_event]);
    
    struct timeval t;
    t.tv_sec =2;
    t.tv_usec =0;
    
    evtimer_add( ev_timers_gl_array[free_event] , &t);

    event_base_dispatch(ev_base);


}