[!VAR "Sum"="0"!]
[!MACRO "TinhTong","Go"="1","x" = "1","y" = "2"!] [!// Giá trị này là default value
    [!IF "num:i($Go)='1'"!]
        [!VAR "Sum"="num:i($x) + num:i($y)"!]
    [!ENDIF!]
[!ENDMACRO!]