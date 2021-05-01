program n_1;
var x,y,x0,y0,r:real;
begin 
writeln('Запишите координаты центра окружности >>');
write('x0=');
read(x0);
write ('y0=');
read(y0);
writeln('Введите координаты точки, через которую проходит окружность >>');
write('x=');
read(x);
write('y=');
read(y);
if (y0=0) and (x0=0) then
r :=sqr(x)+sqr(y) else
r := sqr(x-x0)+sqr(y-y0);
sqrt(r);
writeln('Ответ:');
writeln('Квадрат радиуса окружности равен');
writeln('r=',r);
writeln('Радиус окружности равен');
writeln('r=',sqrt(r));
end.
