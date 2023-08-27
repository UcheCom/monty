[ This program read 2 digits from stdin, multiplies them and prints out the result]
,>,    	       	      Reads the 2 digits in cell #0 and cell #1
>++++++++	      Remove 48 to value in cell #0 and cell #1
[
	<------
	<------
	>>-
]
<<		      Go to cell #0
[
	>	      Go to cell #1
	[
		-     Substract 1 to cell #1
		>+    move data to cell #2
		>+    move data to cell #3
		<<    go back to cell #1
	]
	>>	      Go to cell #3
	[
		-     Substract 1 to cell #3
		<<+   Add 1 to cell #1
		>>    Go back to cell #3
	]
	<<<-	      substrack 1 to cell #0
]
++++++++	      Add 48 to the result store in cell #2 and prints
[
	>>++++++
	<<-
]
>>.
