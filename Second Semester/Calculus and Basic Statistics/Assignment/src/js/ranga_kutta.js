// enter the value of y0
let y_0 = 1
// enter the value of x0
let x_0 = 0
// enter the value of x at which point you want to find value of y
let x_final = 0.2
// Enter the value of h by sliding this thing
let h = 0.1

values_of_x = []

for (let i = x_0; i <= x_final; i+=h) {
  values_of_x.push(i)
}
console.log(values_of_x);
// Enter the function 
let given_f = "x+y^2"

const f_x (x, y) =>
{
  return 1
}

for i in values_of_x:
  let y_1 = y_0 + h * f_x(x_0, y_0)
  let k_1 = h * f_x(x_0, y_0)
  let k_2 = h * f_x(x_0 + h/2, y_0 + k_1/2)
  let k_3 = h * f_x(x_0 + h/2, y_0 + k_2/2)
  let k_4 = h * f_x(x_0 + h/2, y_0 + k_3/2)
  
  let k = 1/6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4)

  y_1 = y_0 + k
  values_of_y.push(y_1)




