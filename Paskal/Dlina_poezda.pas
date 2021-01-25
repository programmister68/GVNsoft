  program n_6;
  var p1,p2,sp,t,switch:integer; sp1,l:real;
    begin
      writeln('Введите скорость поезда');
      readln(p1);
      writeln('Укажите скорость пешехода');
      readln(p2);
      writeln('Введите время (в секундах)');
      readln(t);
      writeln('Обозначьте тип задачи ("1" - Движение на встречу; "0" - Движение в одну сторону)');
      readln(switch);
      if switch=1 then
      begin 
        sp:=p1+p2;
        sp1:=(sp*1000)/3600;
        l:=sp1*t;
        writeln('Длина поезда равна = ',l:0:2,' М');
      end;
      
      if switch=0 then 
      begin 
      sp:=p1-p2;
        sp1:=(sp*1000)/3600;
        l:=sp1*t;
        writeln('Длина поезда равна = ',l:0:2,' М');
      end; 

    end.