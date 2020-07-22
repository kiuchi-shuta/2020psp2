# 課題4 レポート

bb35319018 木内柊汰

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
6:構造体を定義

23: データファイル名を入力させ，fnameに格納

24: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列
の最後をヌル文字'\0'に置換

25: fnameを確認

27: fnameで指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

28: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

33: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

38: bufからscanf身長と性別を読み込む

39: 数値の個数をカウント

42: ファイルを閉じる．閉じれないときは，即座にプログラム終了.

48: データファイル名を入力させ，fnameに格納

49: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

50: fnameを確認

52: fnameで指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

53: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

59: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

60: bufからscanfでidを読み込む

61: 数値の個数をカウント

63: ファイルを閉じる．閉じれないときは，即座にプログラム終了.

68:idを入力させる

71:idがあるものが入力された場合、性別が男性か女性かを判別し、男性の場合male、女性の場合femaleと表示し慎重を表示

89:idがない場合NO dataと表示



## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

```
PS C:\Users\bb35319018\新しいフォルダー (7)\2020psp2\k04> ./k04
Input the filename of sample height:c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\heights.csv
the filename of sample: c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\heights.csv
Input the filename of sample ID:c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\IDs.csv
the filename of sample: c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\IDs.csv
Which ID's data do you want? :45313125
ID : 45313125
gender : female
height : 152.4

PS C:\Users\bb35319018\新しいフォルダー (7)\2020psp2\k04> ./k04
Input the filename of sample height:c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\heights.csv
the filename of sample: c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\heights.csv
Input the filename of sample ID:c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\IDs.csv
the filename of sample: c:\Users\bb35319018\新しいフォルダー (7)\2020psp2\sample\IDs.csv
Which ID's data do you want? :45313124
No data
PS C:\Users\bb35319018\新しいフォルダー (7)\2020psp2\k04>
```

## 修正履歴
[comment #20200721]
- OKです

[comment #20200722 sonoda]
- 課題4の完了を確認しました
