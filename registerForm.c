  case 0x80:      //ADD B    
        {    
            // do the math with higher precision so we can capture the    
            // carry out    
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->b;    

            // Zero flag: if the result is zero,    
            // set the flag to zero    
            // else clear the flag    
            if ((answer & 0xff) == 0)    
                state->cc.z = 1;    
            else    
                state->cc.z = 0;    

            // Sign flag: if bit 7 is set,    
            // set the sign flag    
            // else clear the sign flag    
            if (answer & 0x80)    
                state->cc.s = 1;    
            else    
                state->cc.s = 0;    

            // Carry flag    
            if (answer > 0xff)    
                state->cc.cy = 1;    
            else    
                state->cc.cy = 0;    

            // Parity is handled by a subroutine    
            state->cc.p = Parity( answer & 0xff);    

            state->a = answer & 0xff;    
        }    

    //The code for ADD can be condensed like this    
    case 0x81:      //ADD C    
        {    
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->c;    

            state->cc.z = ((answer & 0xff) == 0);    
            state->cc.s = ((answer & 0x80) != 0);    
            state->cc.cy = (answer > 0xff);    
            state->cc.p = Parity(answer&0xff);    
            state->a = answer & 0xff;    
        }    
