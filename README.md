# Вариант 9

## Практика 9
  Общее условие:
Определить структурный тип, описывающий маркетплейсы (название 
маркетплейса, количество ПВЗ по стране, город дислокации, рыночная стоимость, 
тип маркетплейса: продуктовый, товары для дома, все-подрял; тип бизнеса 
компании: основной, вспомогательный, франшиза и др.). Заполнить структурный 
массив 20-ю записями. Переписать из исходного массива в другой массив, 
информацию только о продуктовых маркетплейсах. Затем новый массив 
отсортировать по количеству ПВЗ. Вывести все данные по конкретному 
маркетплейсу. Вывести 3 самых популярных маркетплейса. Реализовать функцию 
изменения данных о маркетплейсе. В отдельный массив поместить все 
маркетплейсы не из Москвы. Реализовать вывод отфильтрованных данных в виде 
оберточной функции. 

  Структурный массив маркетплейсов инициализирован в int main()

  Условие: Переписать в другой массив информацию только о продуктовых 
маркетплейсах, затем отсортировать по количеству ПВЗ
Функции: GroceriesMarketplaces()
Вывод:
========================================
Grocery marketplaces (by quantity ascending):
========================================
MangoMango	13
Allegro	48
Jumia	61
Coupang	82
Pinduoduo	95
========================================

  Условие: Вывести все данные по конкретному маркетплейсу
Функции: SearchName()
Вывод (если найден "Amazon"):
========================================
Enter marketplace name to search: Amazon
========================================

Marketplace found:
Name: Amazon
Quantity: 112
Country: us
City: NewYork
Networth: 34056300
Type: all
Business: corporation
========================================

Вывод (если не найден):
========================================
Enter marketplace name to search: Test
========================================
Marketplace not found!
========================================

  Условие: Вывести 3 самых популярных маркетплейса
Функции: Top3Popular()
Вывод:
========================================
Top 3 most popular marketplaces:
========================================
1. Amazon - 112
2. Pinduoduo - 95
3. AliExpress - 88
========================================

  Условие: Реализовать функцию изменения данных о маркетплейсе
Функции: ChangeMarketplaceData()
Вывод:
========================================
What do you want to change?
name, quantity, country, city, networth, type, business
========================================
[ввод поля]
Enter new [поле]: [ввод значения]
[Поле] updated successfully!

  Условие: В отдельный массив поместить все маркетплейсы не из Москвы
Функции: NotMoscow()
Вывод:
========================================
Marketplaces not from Moscow:
========================================
Amazon - NewYork
AliExpress - SaintPetersburg
Abeme - London
MangoMango - Koln
Rozetka - SaintPetersburg
Pinduoduo - Shanghai
Wayfair - Boston
Allegro - Poznan
Gmarket - Seoul
Snapdeal - NewDelhi
Coupang - Seoul
TradeMe - Auckland
Myntra - Bangalore
Newegg - CityOfIndustry
Zalora - Singapore
Jumia - Lagos
Linio - MexicoCity
Souq - Dubai
========================================

  Условие: Реализовать вывод отфильтрованных данных в виде обёрточной функции
Функции: SortMenu()
Вывод:
========================================
Select sorting option:
========================================
1. Show marketplaces not from Moscow
2. Show Top 3 most popular marketplaces
3. Show grocery marketplaces (by quantity ascending)
========================================
Enter your choice (1-3): [ввод]
========================================
[результат выбранной сортировки]

## Практика 10
### №1
  Условие:
Считать из текстового файла данные числового поля для вашей.
Функции: main() — блок с ifstream fin("prac10.txt")
Вывод:
Prac10.1
Numeric values from file:
112
23
88
78
13
56
42
95
31
48
39
44
82
27
36
53
28
61
33
47

### №2
  Условие:
Сделать чтение / запись своей структуры в бинарный файл. Оформить в виде подпрограмм. 
Функции: WriteToBinaryFile(), ReadFromBinaryFile(), DisplayData()
Вывод:
Prac10.2
Data written to marketplace.bin successfully
Read 20 records from marketplace.bin

========================================
Marketplace Data:
========================================
Amazon | 112 | us | NewYork | 34056300 | all | corporation
Lamoda | 23 | ru | Moscow | 7846600 | clothes | base
AliExpress | 88 | ch | SaintPetersburg | 5325315 | all | franchise
Abeme | 78 | uk | London | 97203700 | home | side
MangoMango | 13 | de | Koln | 932000 | grocieries | small
YandexMarket | 56 | ru | Moscow | 8750000 | tech | corporation
Rozetka | 42 | ru | SaintPetersburg | 3450000 | home | side
Pinduoduo | 95 | cn | Shanghai | 56700000 | grocieries | franchise
Wayfair | 31 | us | Boston | 11200000 | home | corporation
Allegro | 48 | pl | Poznan | 7680000 | grocieries | base
Gmarket | 39 | kr | Seoul | 6540000 | clothes | franchise
Snapdeal | 44 | in | NewDelhi | 3210000 | tech | small
Coupang | 82 | kr | Seoul | 23400000 | grocieries | corporation
TradeMe | 27 | nz | Auckland | 2980000 | all | side
Myntra | 36 | in | Bangalore | 4320000 | clothes | franchise
Newegg | 53 | us | CityOfIndustry | 7650000 | tech | corporation
Zalora | 28 | sg | Singapore | 1980000 | clothes | small
Jumia | 61 | ng | Lagos | 5430000 | grocieries | franchise
Linio | 33 | mx | MexicoCity | 2870000 | tech | base
Souq | 47 | ae | Dubai | 6210000 | home | side
========================================

