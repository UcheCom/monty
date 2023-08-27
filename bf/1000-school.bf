[ This program prints "School" and a newline to the screen
]
++++++++                        Set cell #0 to 8
[
	>+++                    Add 3 to the cell #1;
	[
		>+++            Add 3 to cell #2;
		>++++           Add 4 to cell #3;
		<<-             Decrement the loop counter in cell #1
	]
	>+                      Add 1 to cell #2
	>>+                     Add 1 to cell #4
	[<]                     Move back to the first zero cell; cell #1

	<-                      Decrement the loop counter in cell #0
]                               Loop until cell #0 is zero; 8 iterations
>>+++.                          Add 3 to cell #2 which makes it be 83 equal to 'S'
>+++.+++++.+++++++..---.        Add 3 output 'c' add 5 and output 'h' add 7 and
                                output 'oo' substract 3 and output 'l'
>++.                            Add 2 to cell #4 and output '\n'
