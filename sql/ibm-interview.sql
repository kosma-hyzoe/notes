SELECT Produkt, SUM(Przychód) AS Kasa, SUM(Ilość) AS Ile, (SUM(Przychód)/SUM(Ilość))
AS Jednostkowo FROM dane1.exports GROUP BY Produkt
ORDER BY Jednostkowo DESC;

SELECT 3 * 21;
