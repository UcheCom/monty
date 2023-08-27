[ This program adds 2 digits read in stdin and prints out the result]
,>,                      Read the 2 inputs in cell #0 and cell #1
[
	<+               Increment the cell #0 by 1
	>-               Decrement cell #1 by 1
]
++++++++		 Set cell #1 to 8
[
	<------          Substract 6 from cell #0
	>-               subtract 1 from cell #1
]
<.                       Prints out cell 0 which has the value a plus b plus 48
