#include <stdio.h>

int main() {
    int n_days, max_days, i, j, buy_date, sell_date, stocks_number, aux;
    float budget, buy_value = 0, sell_value, profit;

    scanf("%d", &n_days);

    float P[n_days];

    // Scanning the sotcks value for each day
    for ( i = 0 ; i < n_days ; i++ )
        scanf("%f", &P[i]);

    scanf("%d", &max_days);

    scanf("%f", &budget);

    profit = -1;

    /*
     * The outter for loop gets each stocks value from the first date untill the last one.
     * The inner for loop gets the subsequent stocks value untill the days' limit or untill the last available day.
     * The if cause inside the for loop evaluates the profit of each iteration and saves the profit, the buy value,
     * the buy date, the sell value and the sell date of the iteration with the highest profit untill that date,
     * if the buy value is smaller than the budget.
     */
    for (i = 0; i < n_days; i++) {
        if (max_days >= (n_days - i - 1)) {
            aux = (n_days - i - 1);
        }
        else {
            aux = max_days;
        }
        for (j = i; j <= i+aux ; j++) {
            if ( ((int) budget / P[i]) * (P[j] - P[i]) > profit && budget >= P[i]) {
                profit = ((int)(budget / P[i])) * (P[j] - P[i]);
                buy_value = P[i];
                buy_date = i + 1;
                sell_value = P[j];
                sell_date = j + 1;
            }
        }
    }

    if ( buy_value == 0 ) {
        buy_value = P[0];
        sell_value = P[0];
        buy_date = 1, sell_date = 1;
    }

    stocks_number = budget / buy_value;
    profit = stocks_number * (sell_value - buy_value);



    // Printing the output
    printf("Dia da compra: %d\n", buy_date);
    printf("Valor de compra: R$ %.2f\n", buy_value);
    printf("Dia da venda: %d\n", sell_date);
    printf("Valor de venda: R$ %.2f\n", sell_value);
    printf("Quantidade de acoes compradas: %d\n", stocks_number);
    printf("Lucro: R$ %.2f\n", profit);

    return 1;
}
