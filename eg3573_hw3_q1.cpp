#include <iostream>
using namespace std;

int main()
{
    //varible declaration
    float priceOneF;
    float priceTwoF;
    float fullPriceItem;
    float halfPriceItem;
    float taxRate;
    char membershipStatus;
    float basePrice;
    float discountPrice;
    float totalPrice;




    //get user input
    cout<<"Enter price of first item:";
    cin>>priceOneF;
    cout<<endl;
    cout<<"Enter price of second item:";
    cin>>priceTwoF;
    cout<<endl;
    cout<<"Does customer have a club card? (Y/N):";
    cin>>membershipStatus;
    cout<<endl;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;
    cout<<endl;


    //if statments to calculate results
    //half price if-statment
    if(priceOneF>priceTwoF){
        halfPriceItem = priceTwoF * .5;
        fullPriceItem = priceOneF;
    }
    else{
        halfPriceItem = priceOneF * .5;
        fullPriceItem = priceTwoF;
    }

    //base price calculation
    basePrice = priceOneF + priceTwoF;

    //member status if-statment
    if(membershipStatus == 'y' or membershipStatus == 'Y' ){
        discountPrice = .90*(halfPriceItem + fullPriceItem);
    }
    else{
        discountPrice = halfPriceItem + fullPriceItem;
    }
    totalPrice = discountPrice + (discountPrice * (taxRate /100)) ;

    //display results to user
    cout<<"Base price: "<<basePrice<<endl;
    cout<<"Price after discounts: "<<discountPrice<<endl;
    cout<<"Total price: "<<totalPrice<<endl;


    return 0;
}