

#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)



int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}
void Can_TX(void)
{

CAN_NODE_STATUS_t status_1; // variable for struct
const CAN_NODE_t *HandlePtr1 = &CAN_NODE_0;

uint8_t can_data_arr[1]={0};

    if((DIGITAL_IO_GetInput(&DIGITAL_IO_0)) == 1)
    		  {
    			  DIGITAL_IO_ToggleOutput(&DIGITAL_IO_2);

    			  can_data_arr[1] = 1;

    			  (CAN_NODE_STATUS_t)CAN_NODE_MO_UpdateData(HandlePtr1->lmobj_ptr[0],can_data_arr);
    		  CAN_NODE_MO_Transmit(HandlePtr1->lmobj_ptr[0]);

    		  }
    else if((DIGITAL_IO_GetInput(&DIGITAL_IO_1)) == 1)
    		  {


    			  DIGITAL_IO_ToggleOutput(&DIGITAL_IO_3);
    			  can_data_arr[1] = 2;

    			  (CAN_NODE_STATUS_t)CAN_NODE_MO_UpdateData(HandlePtr1->lmobj_ptr[0],can_data_arr);
    			 CAN_NODE_MO_Transmit(HandlePtr1->lmobj_ptr[0]);

    		  }




  else
  {
	  can_data_arr[1] = 0;
  }
}


