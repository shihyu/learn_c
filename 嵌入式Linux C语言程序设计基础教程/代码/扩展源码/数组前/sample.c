#include <stdio.h>
#include <stdlib.h>

#define MAX 64

typedef struct
{
   int data[MAX];
   int top;
} sqstack;


void setnull(sqstack *s)
{
   s->top = -1;
}

int empty_stack(sqstack *s)
{
   return ( s->top == -1 );
}

int push_stack(sqstack *s, int value)
{
   if ( s->top == (MAX - 1) )
   {
      printf("Overflow!\n");
      return -1;
   }
   
   s->top++;
   s->data[s->top] = value;
 
   return 0;
} 

int pop_stack(sqstack *s)
{
   if ( empty_stack(s) )
   {
      printf("Underflow!\n");
      return -1;
   }
   s->top--;
 
   return s->data[s->top+1];  
}

int top_stack(sqstack *s)
{
   if ( empty_stack(s) )
   {
      printf("Empty stack!\n");
      return -1; 
   }

   return s->data[s->top];
}



int convert_operator(char c)
{
   switch ( c )
   {
      case '+' : 
      case '-' :
                return 1;
      case '*' :
      case '/' :
                return 2;
      case '(' :
                return 3;
   }
}



void deal_tmp(sqstack *operator, sqstack *operand, char ch)
{
   int op1, op2;

   while ( convert_operator(ch) <= convert_operator((char)top_stack(operator)) )
   {
      op2 = pop_stack(operand);
      op1 = pop_stack(operand);
      switch ( (char)pop_stack(operator) )
      {
         case '+' :
                   printf("push data: %d + %d\n", op1, op2);
                   push_stack(operand, op1 + op2);
                   break;
         case '-' :
                   printf("push data: %d - %d\n", op1, op2);
                   push_stack(operand, op1 - op2);
                   break;
         case '*' :
                   printf("push data: %d * %d\n", op1, op2);
                   push_stack(operand, op1 * op2);
                   break;
         case '/' :
                   printf("push data: %d / %d\n", op1, op2);
                   push_stack(operand, op1 / op2);
                   break;
      }
      if ( empty_stack(operator) || ((char)pop_stack(operator) == '(') ) 
      {
         break;
      }      
   }
   push_stack(operator, (int)ch);
}



void deal_bracket(sqstack *operator, sqstack *operand)
{
   int op1, op2;


   while ( (char)top_stack(operator) != '(' )
   {
      op2 = pop_stack(operand);
      op1 = pop_stack(operand);
      switch ( (char)pop_stack(operator) )
      {
         case '+' :
                   printf("push data: %d + %d\n", op1, op2);
                   push_stack(operand, op1 + op2);
                   break;
         case '-' :
                   printf("push data: %d - %d\n", op1, op2);
                   push_stack(operand, op1 - op2);
                   break;
         case '*' :
                   printf("push data: %d * %d\n", op1, op2);
                   push_stack(operand, op1 * op2);
                   break;
         case '/' :
                   printf("push data: %d / %d\n", op1, op2);
                   push_stack(operand, op1 / op2);
                   break;
      }
   } 
   pop_stack(operator);    
}



/*********************************************/
int main()
{
   char expression[30],*p;
   sqstack *operator, *operand;
   int sum, flag = 0;
   int op1, op2;

   operator = (sqstack *)malloc(sizeof(sqstack));
   setnull(operator);
   operand = (sqstack *)malloc(sizeof(sqstack));
   setnull(operand);

   gets(expression);
   p = expression;

   while ( *p )
   {
      if ( (*p >= '0') && (*p <= '9') ) 
      {  
         p++;
         continue;
      }
      switch ( *p )
      {
         case '+' :
         case '-' :
         case '*' :
         case '/' :
         case ' ' :
         case '(' :
         case ')' :  
                   break;
         default  :
                   printf("Wrong Character %c in expression!\n", *p);
                   return -1;
      }
      p++;
   }

   p = expression;
   while ( *p )
   {
      if ( (*p >= '0') && (*p <= '9') )
      {
         if ( flag )
         {
            sum = 10*sum + (*p - '0');
         }
         else
         {
            sum = *p - '0';
            flag = 1;
         }
         p++;
         continue;
      }
     
      if ( flag )
      {
         printf("push data %d\n", sum);
         push_stack(operand, sum);
         flag = 0;
      }

      if ( *p == ' ' )
      {
         p++;
         continue;
      }      

      if ( empty_stack( operator ) )
      {
         printf("push %c\n", *p);
         push_stack(operator, (int)*p);
         p++;
         continue;
      }
      
      if ( *p == ')' )
      {
         printf("*** Wow, we meet ) ***\n");
         deal_bracket(operator, operand);
         p++;
         continue;
      }

      if ( (convert_operator(*p) > convert_operator((char)top_stack(operator))) || ((char)top_stack(operator) == '(') )
      {
         printf("push %c\n", *p);
         push_stack(operator, (int)*p);
      }
      else
      {
         deal_tmp(operator, operand, *p);
      }
      p++;
   }
   if ( flag )  push_stack(operand, sum);
 
   while ( !empty_stack(operator) )
   {
      op2 = pop_stack(operand);
      op1 = pop_stack(operand);
       
      switch ( (char)pop_stack(operator) )
      {
         case '+' :
                   printf("push data: %d + %d\n", op1, op2);
                   push_stack(operand, op1 + op2);
                   break;
         case '-' :
                   printf("push data: %d - %d\n", op1, op2);
                   push_stack(operand, op1 - op2);
         case '*' :
                   printf("push data: %d * %d\n", op1, op2);
                   push_stack(operand, op1 * op2);
                   break;
         case '/' :
                   printf("push data: %d / %d\n", op1, op2);         
                   push_stack(operand, op1 / op2);
                   break;
      }
   }   
        
   printf("%d\n", pop_stack(operand));

   return 0;
}
