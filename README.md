Welcome! This is the balance calculator for spliting the bill.

## How to enter input?
The program will read input from input.txt file with the following format
```
person1 person2 person3  amount

# person1, person2, until person k will split the amount.
# amount if the price for single item. if this item has tax, the user can add an 'a' or 'A' at the end of the price. Then user can modify CURRENT_LOCATION and city_to_tax_rate for the purpose of incorporating tax into calculation. 
```

## Example:
Simon buys cara orange for $11.99 
Simon and Eric buys Beef Stew for $17.74
Eric buys TIDE for 24.99 with tax (in New Haven)
Simon pays the bill for 56.30

The user can enter the following in input.txt
```
simon 11.99
simon eric 17.74
eric 24.99a
simon -56.30
```

The program will output
```
====================
eric 35.4469
simon -35.44
====================
```
Eric simply transfers 35.44 to Simon, and the bill is calculated! 


