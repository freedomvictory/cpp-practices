# class operator function 


```c++ 
//.h file 
class TempFlowDatas{

public:
    float CataConvertTemp;
    float DecetorTemp;
    float H2GasFlow;
    float CarrierGasFlow;
    float AirFlow;
    
    friend bool operator ==(const TempFlowDatas &ldata, const TempFlowDatas &rdata)
     {
         if(ldata.CataConvertTemp == rdata.CataConvertTemp && ldata.DecetorTemp == rdata.DecetorTemp
                 && ldata.H2GasFlow ==  rdata.H2GasFlow && ldata.CarrierGasFlow ==  rdata.CarrierGasFlow
                 && ldata.AirFlow ==  rdata.AirFlow)
         {
             return true;
         }
         else
         {
             return false;
         }
     }

};
```

**NOTE**

we have to define the `operator ==` function inside the class. or define the `operator ==` on cpp file . or define the `operator` as an `inline` function. else, we will got an error 

```
multiple definitions of operator `==`
```

```c++
//.h file 
class TempFlowDatas{

public:
    float CataConvertTemp;
    float DecetorTemp;
    float H2GasFlow;
    float CarrierGasFlow;
    float AirFlow;
    
    friend bool operator ==(const TempFlowDatas &ldata, const TempFlowDatas &rdata);


};
// error: multiple definitions 
  friend bool operator ==(const TempFlowDatas &ldata, const TempFlowDatas &rdata)
     {
         if(ldata.CataConvertTemp == rdata.CataConvertTemp && ldata.DecetorTemp == rdata.DecetorTemp
                 && ldata.H2GasFlow ==  rdata.H2GasFlow && ldata.CarrierGasFlow ==  rdata.CarrierGasFlow
                 && ldata.AirFlow ==  rdata.AirFlow)
         {
             return true;
         }
         else
         {
             return false;
         }
     }
```
That means we break the `one definition rule`. We are putting the *definition* in a `.h` file ,which means that it will appear in every translation unit. (=> we defined `operator<<` in every object module, so the linker doesn't know which is "the right one") 
