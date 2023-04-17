 using System;
 class Program  
      {  
          // function without any return type declaration  
         public void Fibonacci(int till, int previo = 0, int actual = 1, int iter = 0)  
         {  
            if (till == iter)
            {
                Console.WriteLine("Resultado: " + previo);
            }
            else{
                int moment = actual;
                actual = previo + actual;
                previo = moment;
                iter++;
                Fibonacci(till, previo, actual, iter);
            }


          }  
          
          public static void Main(string[] args)  
         {  
            Program pr = new Program();
            pr.Fibonacci(2);
         }  
    }