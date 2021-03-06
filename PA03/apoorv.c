    /*************** Gauss Jordan method for inverse matrix ********************/

    #include<stdio.h>
       
  int main()
    {
        int i, j, k, n;
        float a[3][3] , d;
	printf("No of Equations?");
	n = 3;
	printf("Read all coeff of the matrix with b matrix too");

	// Just reading in the data
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                scanf("%f", n);   
	// At this point the data you want is stored in "a"                
	
        for (i = 1; i <= n; i++)
            for (j = 1; j <= 2 * n; j++)
                if (j == (i + n))
                    a[i][j] = 1;

        /************** partial pivoting **************/
        
        for (i = n; i > 1; i--)
        {
           if (a[i - 1][1] < a[i][1])
                for (j = 1; j <= n * 2; j++)
                {
                    d = a[i][j];
                    a[i][j] = a[i - 1][j];
                    a[i - 1][j] = d;
                }
        }
        printf("pivoted out");
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n * 2; j++)
               printf("%f ",a[i][j]);
            printf("\n");
        }
        /********** reducing to diagonal  matrix ***********/  
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n * 2; j++)
               if (j != i)
                {
                    d = a[j][i] / a[i][i];
                    for (k = 1; k <= n * 2; k++)
                        a[j][k] -= a[i][k] * d;
                }
        }

        /************** reducing to unit matrix *************/
        for (i = 1; i <= n; i++)
        {
            d = a[i][i];
           for (j = 1; j <= n * 2; j++)
                a[i][j] = a[i][j] / d;
        }     

        printf("your solutions: \n");
        for (i = 1; i <= n; i++)
        {
            for (j = n + 1; j <= n * 2; j++)
                printf( "%f    ",a[i][j]);
            printf("\n");
        }     
        return 0;
    }
