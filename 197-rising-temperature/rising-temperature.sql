/* Write your PL/SQL query statement below */
select w2.id Id from Weather w1 join Weather w2 on w2.recordDate-w1.recordDate=1 and w1.temperature<w2.temperature;