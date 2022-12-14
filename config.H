#ifndef CONFIG_H
#define CONFIG_H

#define TOTAL_MEMORY 0xFFFF
#define WORD unsigned char
#define DOUBLE_WORD unsigned short

#define ZERO_PAGE_START 0x0000
#define ZERO_PAGE_END 0x00FF
#define ZERO_PAGE_SIZE 0x00FF

#define STACK_START 0x0100
#define STACK_END 0x01FF
#define STACK_SIZE 0x00FF


//LDA opcodes
#define LDA_I 0xA9
#define LDA_ZP 0xA5 
#define LDA_ZP_X 0xB5 
#define LDA_ABS 0xAD
#define LDA_ABS_X 0xBD 
#define LDA_ABS_Y 0xB9 
#define LDA_IND_X 0xA1 
#define LDA_IND_Y 0xB1 

//JSR opcodes
#define JSR_ABS 0x20

//ADC opcodes
#define ADC_I 0x69
#define ADC_ZP 0x65
#define ADC_ZP_X 0x75
#define ADC_ABS 0x6D
#define ADC_ABS_X 0x7D
#define ADC_ABS_Y 0x79
#define ADC_IND_X 0x61
#define ADC_IND_Y 0x71








#endif