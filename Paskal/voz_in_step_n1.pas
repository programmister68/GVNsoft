program woz_in_step;
var a, n, i, d, f:integer; s: real;
  begin
  writeln ('Запишите число >>');
  readln(a);
  writeln ('Запишите степень числа>>');
  readln(n);
  f:=1;
  if n>0 then
    for i:=1 to n do
    begin
    f:=(f*a);
    s:=f
    end;
   if n=0 then
    begin
    s:=1;
    end;
  if n<0 then 
    for i:=1 downto n do
    begin
    d:=(f*a);
    s:=1/d;
    end;    
  writeln('Ответ:',s)
  end.