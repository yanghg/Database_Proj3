-- login procedure
delimiter //
drop procedure if exists login//
CREATE PROCEDURE login(in username varchar(20), in userpassword varchar(10), out flag boolean)
begin
	if exists (select * from student where username = Name and userpassword = password) then
		set flag = true;
	else 
		set flag = false;
	end if;
end//

delimiter ;
