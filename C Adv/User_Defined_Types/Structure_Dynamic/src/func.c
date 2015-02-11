/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include "name_det_header.h"

/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/
static name_ret remove_newline(char *);
static name_ret allocate_person(person_name_et **, int, int);

/****************************************************************************
*
*       Function Name   : remove_newline
*       Description     : Removes \n, if any, from the array
*       Returns         : Success or Failure
*
****************************************************************************/
static name_ret remove_newline(
                               char *arg_input /* input string */
                       	      )
{
  if(NULL == arg_input) /* Error handling for argument */
  {
   return FAILURE;
  }

  /* Finds out the length of the string */
  size_t str_len = strlen(arg_input);

  /* Checks whether a '\n' is appended at the end */
  if('\n' == arg_input[str_len - 1])
  {
   arg_input[str_len - 1] = '\0'; /* Replaces '\n' with '\0' */
  }
  return SUCCESS;
}
/****************************************************************************
*
*       Function Name   : allocate_person
*       Description     : Allocates memory for structure and elements
*       Returns         : Success or Failure
*
****************************************************************************/
static name_ret allocate_person(
				person_name_et **person, /* ptr to person */ 
				int len_first, /* Length of first name */
				int len_second /* Length of second name */
			       )
{
 *person = (person_name_et *)malloc(sizeof(person_name_et));
 if(NULL == person)
 {
  printf("Malloc failure\n");
  return FAILURE;
 }
 (*person)->first_name = (char *)malloc(len_first * sizeof(char)); 
 if(NULL == (*person)->first_name)
 {
  printf("Malloc failure\n");
  return FAILURE;
 }
 (*person)->second_name = (char *)malloc(len_first * sizeof(char)); 
 if(NULL == (*person)->second_name)
 {
  printf("Malloc failure\n");
  return FAILURE;
 }
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : update_person
*       Description     : Copies the 1st & 2nd name to each array element
*       Returns         : Success or Failure
*
****************************************************************************/
name_ret update_person(
			person_name_et **person, /* Ptr to structure */
			char *first_arg, /* First name */
			char *second_arg /* Second name */
		      )
{
 /* Implemente this function which update each array element */
}
 
/****************************************************************************
*
*       Function Name   : display_person
*       Description     : Dispay the contents of the person array
*       Returns         : Success or Failure
*
****************************************************************************/
name_ret display_person(
			person_name_et *arg_person[], /* Array of persons */
			int arg_total /* Total number of persons */
		       )
{
 int index = 0; /* for loop index */
 for(index = 0; index < arg_total; index += 1)
 {
  printf("person - %d\t", index + 1);
  printf("First Name - %s\t", arg_person[index]->first_name); 
  printf("Second Name - %s\n", arg_person[index]->second_name); 
 }
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : free_person
*       Description     : Deallocates memory allocated for person array
*       Returns         : Success or Failure
*
****************************************************************************/
name_ret free_person(
                      person_name_et *arg_person[], /* Array of persons */
                      int arg_total /* Total number of persons */
                    )
{
 /* Implement this function to deallocate the memory */
}
