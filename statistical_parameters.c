#include <stdio.h>
#include <math.h> 

void statistical_switch_board(int choice,int number_of_elements,float numbers_array[50]);

int main()
{
int number_of_elements, choice;
float numbers_array[50];
printf("Enter the number of elements you want to enter: ");
scanf("%d", &number_of_elements);
printf("Enter the numbers\n");		
for (int i=0; i<number_of_elements; i++)
	{
	scanf("%f", &numbers_array[i]);
	}

printf("What you want to do? \n 1. Mean \n 2. Median \n 3. Mode \n 4. Variance \n 5. Standard Deviation \n");
printf("Enter your choice: ");
scanf("%d", &choice);
statistical_switch_board(choice,number_of_elements,&numbers_array[0]);

return 0;
}

void statistical_switch_board(int choice,int number_of_elements,float numbers_array[50])
{
	int selected_choice = choice;
	float number;
	switch (selected_choice)
	{

	case 1: 
		{
		float mean_ans;
		for (int i=0; i<number_of_elements; i++)
			{
			number = number + numbers_array[i];
			}
		mean_ans = (number/number_of_elements);
		printf("The Mean of entered numbers is %f \n", mean_ans);
		}
		break;

	case 2: 
		{
		if (number_of_elements%2 == 0)
			{
			int num1 = (number_of_elements/2)-1;
			float median = (numbers_array[num1]+numbers_array[num1+1])/2;
			printf("%f: ",median);
			}
		else
			{
			int median = ((number_of_elements+1)/2)-1;
			printf("%f: ",numbers_array[median]);			
			}
		}		
		break;
	case 3: 
		{
		    for (int i = 0; i < number_of_elements; ++i)
		    {
			for (int j = i + 1; j < number_of_elements; ++j)
			{
			    if (numbers_array[i] > numbers_array[j])
			    {
				float a;
				a =  numbers_array[i];
				numbers_array[i] = numbers_array[j];
				numbers_array[j] = a;
			    }
			}
		    }
		number = numbers_array[0];
		int mode = number;
		int count = 1;
		int countMode = 1;
		for (int i=1; i<number_of_elements; i++)
			{
			if (numbers_array[i] == number) 
			      { 
				++count;	// count occurrences of the current number
			      }
			else
			      { 
				if (count > countMode) 
				    {
					countMode = count; // mode is the biggest ocurrences
					mode = number;
				    }
				count = 1; // reset count for the new number
				number = numbers_array[i];
			      }
			}
		printf("Mode : %d \n", mode);
		}			
		break;
	case 4: 
		{
		float variance;
		float mean_ans;
		float number1;
		for (int i=0; i<number_of_elements; i++)
			{
			number = number + numbers_array[i];
			}
		mean_ans = (number/number_of_elements);
		for (int i=0; i<number_of_elements; i++)
			{
			double a = pow(numbers_array[i]-mean_ans,2);
			number1 = number1 + a;
			}
		variance = number1 /(number_of_elements-1);
		printf("Variance: %f \n",variance);	
		}		
		break;
	case 5: 
		{
		float variance,mean_ans;
		double SD;
		float number1;
		for (int i=0; i<number_of_elements; i++)
			{
			number = number + numbers_array[i];
			}
		mean_ans = (number/number_of_elements);
		//printf("Mean %f: \n", mean_ans);
		for (int i=0; i<number_of_elements; i++)
			{
			double a = pow(numbers_array[i]-mean_ans,2);
			number1 = number1 + a;
			//printf("%f \n", number1);
			}
		variance = number1 /(number_of_elements-1);
		SD = sqrt(variance);		
		printf("Standard Deviation(σ): %f\n",SD);	
		}
		break;
	default:
		printf("You entered worng choice \n");
		break;
	}
}
