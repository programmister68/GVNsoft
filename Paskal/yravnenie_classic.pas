program yravnenie_classic;
var x, a, b, s: real; y:string;
begin
  write('Введите первую переменную а=');
  readln(a);
  write('Введите вторую переменную b=');
  readln(b);
  write('Введите результат вычеслений s=');
  readln(s);
  x:=(-(b)+s)/a;
  writeln('Неизвестное значение уравнения ax+b=s равно ',a,'x+',b,'=',s,', x=',x);
end.