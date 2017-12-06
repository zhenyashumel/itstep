select Model, Price, Price - (Price / 100 * Action_Percent) as 'Цена со скидкой' from Products inner join ActionProducts 
on Products.Product_Id = ActionProducts.Product_Id
inner join Actions
on ActionProducts.Action_Id = Actions.Action_Id
where GetDate() < Actions.Date_End and GetDate() > Actions.Date_Begin
union
select Model, Price, Price as 'Цена со скидкой' from Products 
where Product_Id not in (select Product_Id from ActionProducts)
