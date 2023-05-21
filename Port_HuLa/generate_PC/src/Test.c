[!CODE!][!//
[!AUTOSPACING!]
[!/* Template Code ThoNV12 */!]
NodeHienTai = [!"node:name(.)"!] [!// Lấy node hiện tại node:current()
NodeRoot = [!"node:name(/)"!] [!// Bắt đầu từ root, root là thằng ngoài cùng
NodebatDauTuNodeHienTai = [!"node:name(//AUTOSAR)"!] [!// Bắt đầu từ node hiện tại

batdau = [!"node:value(POST_BUILD_VARIANT_USED)"!] [!// Bình thường bắt đầu ở đây
batdau1 = [!"node:value(/AUTOSAR/TOP-LEVEL-PACKAGES/Port/ELEMENTS/Port/POST_BUILD_VARIANT_USED)"!]
batdau2 = [!"node:value(//AUTOSAR/TOP-LEVEL-PACKAGES/Port/ELEMENTS/Port/POST_BUILD_VARIANT_USED)"!]

TestBoolean = [!"node:value(PortGeneral/TestEnable)"!] [!// hay bắt đầu dùng như này
TestInteger = [!"node:value(PortGeneral/TestInteger)"!] 
TestFloat = [!"node:value(PortGeneral/TestFloat)"!] 
TestString = [!"node:value(PortGeneral/TestString)"!] 
GetRange = [!"node:value(PortGeneral/GetRange)"!] 

[!"num:i("123")"!]
[!"node:exists(PortGeneral/TestInteger)"!]
[!"node:name(PortGeneral/*[@name='TestFloat'])"!] [!// Lấy thằng có name='TestFloat'
[!"node:name(PortGeneral/*[@type='BOOLEAN'])"!] [!// Lấy thằng có type='BOOLEAN'
[!"node:name(List_uniq/*[@index=2])"!] [!// Lấy trong thàng list có @index=2
[!"node:name(PortGeneral/*[1])"!] [!// Lấy thằng có position = 1, bắt đầu từ 1

[!// [!VAR "<Variable-Name>" = "<Expression>"!]
[!VAR "Count"= "2"!]
[!"node:name(PortGeneral/*[position() = $Count])"!] [!// Lấy thằng có position=Count
[!"node:name(PortGeneral/*[last()])"!] [!// Lấy thằng cuối cùng
[!"node:name(PortGeneral/*[last()-1])"!] 

[!LOOP "List_uniq/*"!]
    [!"node:value(./Getuniq)"!]
[!ENDLOOP!]

TestInteger = [!"node:value(PortGeneral/TestInteger) + 1"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) - 1"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) * 1"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) div 5"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) mod 3"!] 
[!/* Kết hợp hai tập hợp nút  /top/Module1 | //Module2 => nodes 'Module1' and 'Module2*/!]
TestInteger = [!"node:value(PortGeneral/TestInteger) != 1"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) = 1"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) < 1"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) <= 1"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) and 0"!] 
TestInteger = [!"node:value(PortGeneral/TestInteger) or 0"!] 

[!"node:name(PortGeneral/*[last()])"!]  [!// Trả về số vị trí của nút con cuối cùng 
[!"node:name(PortGeneral/*[position()=1])"!]  [!// Lấy thàng có vị trí đầu tiên

[!// Đếm số lượng thằng con trong List_uniq cách 1
[!"num:i(count(List_uniq/*))"!]  
[!// Đếm số lượng thằng con trong List_uniq cách 2
[!NOCODE!]
    [!VAR "Index" = "0"!]
    [!LOOP "List_uniq/*"!]
        [!VAR "Index" = "num:i($Index + '1')"!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!"$Index"!]  

[!// String-function
[!"concat('tho', 'nv', '12')"!] [!// Nối các chuỗi lại
[!"starts-with('abctest', 'abc')"!] [!// trả về true nếu thằng 1 có phần đầu chứa thằng 2
[!"contains('mnabctest', 'abc')"!] [!// trả về true nếu thằng 1 chứa thằng 2
[!"substring-before( '2000/09/06', '/')"!] [!// trả về trước dấu / đầu tiên
[!"substring-after( '2000/09/06', '/')"!] [!// trả về sau dấu / đầu tiên
[!"substring( 'vantho15', 2,3)"!] [!// Lấy từ vị trí thứ 2 và 3 kí tư
[!"substring( 'vantho15', 2)"!] [!// Lấy từ vị trí thứ 2 tới hết
[!"string-length('12345')"!] [!// length
[!"boolean(5)"!] [!// đúng
[!"not(boolean(0))"!] [!// đúng

[!"number('5')"!] [!// convert chuỗi qua số
[!"sum(PortGeneral/*[(position() <= 3) and (position() >=2)])"!] [!// Tính tổng của tất cả các thằng con
[!"round(1.6)"!] [!// làm tròn

[!"node:name(node:current())"!] [!//
[!// node:islast() dùng để kiểm tra trong FOR LOOP xem đã hết chưa

[!"node:ref(PortGeneral/TestREF)"!] [!// Lấy giá trị của thằng mà referent đang trỏ tới
[!"node:exists(PortGeneral/TestREF)"!] [!// Kiểm tra node này có tồn tại hay không
[!"node:empty(PortGeneral/TestREF)"!] [!// Kiểm tra node có giá trị hay không

[!"node:containsValue(PortGeneral/*,'true')"!] [!// true nếu trong tất cả thằng con có 1 giá trị là true
[!"node:foreach( ecu:list('Gpio.key'), 'x','$x * 2')"!] [!// chạy vòng for cái list resource và nhân 2 từng giá trị

[!// node:fallback(Xpath,"thov")  nếu xpath a đuọc đánh giá là đúng thì lấy biểu thức đánh giá đó, còn không thì lấy giá trị b, tính toán phức tạp thì thêm -> vào trước
[!//expr="(node:fallback(../GetRange,'Core0') = 'Core0')" true="Core0_0"/>

[!// IF
[!IF "node:value(PortGeneral/TestEnable) = 'true'"!]
    true
[!ELSEIF "node:value(PortGeneral/TestEnable) = 'flase'"!]
    flase
[!ELSE!]
    NULL
[!ENDIF!]

[!// FOR
[!FOR "i" = "1" TO "4"!]
    [!"$i"!]
[!ENDFOR!]

[!FOR "i" = "1" TO "4" STEP "2"!]
    [!"$i"!]
[!ENDFOR!]

[!FOR "x" = "1" TO "10"!]
    [!IF "num:i($x) > 3"!][!BREAK!][!ENDIF!]
    [!"$x"!]
[!ENDFOR!]

[!// SELECT
[!SELECT "PortGeneral"!]
    TestFloat = [!"node:value(./TestFloat)"!] 
    TestString = [!"node:value(./TestString)"!] 
    GetRange = [!"node:value(./GetRange)"!] 
[!ENDSELECT!]

[!NOCODE!]
[!INCLUDE "macro.m"!]
[!ENDNOCODE!]
[!CALL "TinhTong","Go"="1","x" = "2","y" = "3"!]   [!// value truyền như xpath vào cũng được
[!"$Sum"!]

[!CALL "TinhTong","Go"="1","x" = "7","y" = "3"!]   [!// value truyền như xpath vào cũng được
[!"$Sum"!]


[!ENDCODE!][!// 