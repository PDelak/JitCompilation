start : statement*;
statement : function_call param*';';
function_call : ('add' | 'mult' | 'sort' | 'filter');
param : (number | logical_expression);
logical_expression : ( '==' | '<=' | '>=');
number              : "[0-9]*" ;