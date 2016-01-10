
# Complete this 'Shopicruit' task we created just for you: You've discovered the
# Shopify Store 'Shopicruit'. Since you're obsessed with computers, you want to 
# buy every single computer and keyboard variant they have to offer. Unfortunately 
# you can only carry up to 100kg and may not be able to buy all of them. By inspecting 
# the JavaScript calls on the store you discovered that the shop lists products at 
# http://shopicruit.myshopify.com/products.json. Write a program that calculates what 
# the maximum amount of computers and keyboards that you could carry would cost you. 
# Attach your answer (in dollars) and your program (any language) and answer in your reply.

############# Solution #######################
# Solution assumes only one of each item. 

#!/usr/bin/env python
import requests
import json
 
class shopicruit:
   
    res = requests.get('http://shopicruit.myshopify.com/products.json')
    # parse json
    dump = json.loads(res.text)
    price = []
    weight = []
    MAX_WT = 100000
 
 
    # extract weight and price lists from json dump
    def get_price_and_weight(self):
        for i in xrange(len(self.dump['products'])):
            if self.dump['products'][i]['product_type'] in ('Computer', 'Keyboard'):
                for j in xrange(len(self.dump['products'][i]['variants'])):
                    self.price.append(self.dump['products'][i]['variants'][j]['price'])
                    self.weight.append(self.dump['products'][i]['variants'][j]['grams'])
 
        # convert from unicode.
        self.price = [float(i) for i in self.price]
        self.weight = [int(i) for i in self.weight]
 
    # 0/1-KnapSack to find optimum price
    def optimum_price(self):
 
        self.get_price_and_weight();
        n = len(self.price)
        V = [[ 0 for x in xrange(self.MAX_WT + 1)] for x in xrange(n+1)]
        # dynamic programming solution to 0/1 knapsack problem
        for i in range(n+1):
            for j in range(self.MAX_WT+1):
                if i==0 or j==0:
                    V[i][j] = 0
                elif self.weight[i-1] <= j:
                    V[i][j] = max(self.price[i-1] + V[i-1][j - self.weight[i-1]], V[i-1][j])
                else:
                    V[i][j] = V[i-1][j]
        return V[n][self.MAX_WT]
       
 
solution = shopicruit()
print solution.optimum_price()
