typedef struct symcpms
{
  char* name;  				/* name of symbol                     			*/
  bool isConst; 			/* flag if symbol is constant					*/
  char* type;    			/* type of symbol							 	*/
  bool isDecleared;  		/* flag if symbol is decleared					*/
  union {
    int ival;       		/* value of an integer          				*/
    float rval;  			/* value of a real         						*/
    char* sval;  			/* value of a string        					*/
  } value;
} symcpm;

static unsigned symhash(char* sym);
symcpm* lookup(char* sym);