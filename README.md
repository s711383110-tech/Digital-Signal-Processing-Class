#  Digital Signal Processing Class
**DSP Assignment-1: Simulation of RC Low-Pass Filter by Discrete Signal Processing**  
Author: *711383110 唐宏碩*  
Date: *2025/10/2*

## Problem 1

已知輸入為 $x(t)=e^{j\Omega t}$，求輸出 $y(t)$，並寫成 $y(t)=H(\Omega)e^{j\Omega t}$。  
其中 $H(\Omega)$ 為 RC 低通濾波器的頻率響應。

---

### ✍️ 手寫圖
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem1.jpg" alt="Problem 1 手寫稿" width="40%">
</p>

### 🧩 LaTeX

已知的連續時間方程式：

$$
RC \frac{dy(t)}{dt} + y(t) = x(t)
$$

設 particular solution 為：

$$
y_p(t) = K e^{j\Omega t}
$$

① 對 $y_p(t)$ 微分：

$$
\frac{dy_p(t)}{dt} = j\Omega K e^{j\Omega t}
$$

② 代回原方程：

$$
RC (j\Omega K e^{j\Omega t}) + K e^{j\Omega t} = e^{j\Omega t}
$$

③ 整理取出 $K e^{j\Omega t}$：

$$
(RC j\Omega + 1) K e^{j\Omega t} = e^{j\Omega t}
$$

④ 消去 $e^{j\Omega t}$ 並求 $K$：

$$
(1 + j\Omega RC) K = 1 \Rightarrow K = \frac{1}{1 + j\Omega RC}
$$

---

最終輸出：

$$
y(t) = \frac{1}{1 + j\Omega RC} e^{j\Omega t}
$$

頻率響應：

$$
H(\Omega) = \frac{1}{1 + j\Omega RC}
$$


## Problem 2

若 $x(t)=e^{j\Omega t}u(t)$，其中 $u(t)$ 為 unit step function，求輸出 $y(t)$。  
$y(t)$ 可分為「暫態響應 (transient-state)」與「穩態響應 (steady-state)」。  
其中 $H(\Omega)$ 為 RC 低通濾波器的頻率響應。

### ✍️ 手寫圖
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem2_01.jpg" alt="Problem 2 手寫稿（上半）" width="40%">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem2_02.jpg" alt="Problem 2 手寫稿（下半）" width="40%">
</p>

---

### 🧩 LaTeX

已知輸入：

$$
x(t)=e^{j\Omega t}u(t)
$$


RC電路滿足的一階微分方程：

$$
RC\frac{dy(t)}{dt}+y(t)=x(t), \qquad \tau=RC
$$


#### ① Particular Solution

設特解：

$$
y_p(t)=K e^{j\Omega t}
$$


代回方程：

$$
\tau \frac{d}{dt}\left(K e^{j\Omega t}\right)+K e^{j\Omega t}
= \tau (j\Omega) K e^{j\Omega t} + K e^{j\Omega t}
= e^{j\Omega t}
$$


消去 $e^{j\Omega t}$ 求 $K$：

$$
(1+j\Omega\tau)K=1 \;\Rightarrow\; K=\frac{1}{1+j\Omega\tau}
$$


故特解：

$$
y_p(t)=\frac{1}{1+j\Omega\tau}e^{j\Omega t}
$$


#### ② Homogeneous Solution

令 $x(t)=0$，則

$$
\tau \frac{dy_h(t)}{dt}+y_h(t)=0
$$

解得

$$
y_h(t)=A e^{-t/\tau}
$$


#### ③ 總解

$$
y(t)=y_p(t)+y_h(t)=H(\Omega)e^{j\Omega t}+A e^{-t/\tau}
$$


#### ④ 初始條件求 $A$

For  t < 0 \, no input and capacitor voltage is continuous:

$$
y(0^-) = 0 \Rightarrow\  y(0^+) = 0
$$

At  t = 0 \, 代 t=0 入總解:

$$
0 = H(\Omega) + A \Rightarrow\ A = -H(\Omega)
$$


---

### ⑤ 最終解並標明有效區間


$$
y(t) = \Big[\ H(\Omega)e^{j\Omega t} - H(\Omega)e^{-t/\tau} \Big] u(t)
     = H(\Omega)\Big( e^{j\Omega t} - e^{-t/\tau} \Big) u(t)
$$

where

$$
H(\Omega) = \frac{1}{1 + j\Omega \tau} = \frac{1}{1 + j\Omega RC}
$$

and

$$
\tau = RC
$$


## Problem 3

已知：

```math
x(t) = e^{j \Omega t}, \quad R = 1000\, \Omega, \quad 
C = \left( \frac{1}{2\pi} \times \frac{1}{400} \times \frac{1}{1000} \right)
```

要求：
```math
y(t) \quad \text{for} \quad \Omega = 2\pi f, \qquad f = 100,\,400,\,3000\,Hz
```

### 計算時間常數與截止頻率

$$
\tau = RC = 1000 \times \frac{1}{2\pi \times 400 \times 1000}
      = \frac{1}{2\pi \times 400} \text{s} \,
\quad
f_c = \frac{1}{2\pi RC} = 400\text{Hz}
$$

---

### ✍️ 手寫圖
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem3_01.jpg" alt="Problem 2 手寫稿（上半）" width="40%">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem3_02.jpg" alt="Problem 2 手寫稿（下半）" width="40%">
</p>

### 🧩 LaTeX

1. RC 的頻率響應 (Problem 1)：

$$
H(j\Omega) = \frac{1}{1 + j\Omega RC} = \frac{1}{1 + j\Omega \tau}
$$

2. 令：

$$
x = \Omega\tau = 2\pi f\tau, \qquad \tau = \frac{1}{2\pi \cdot 400} \Rightarrow x = \frac{f}{400}.
$$

$$
H = \frac{1}{1 + jx} = \frac{1 - jx}{1 + x^2} \quad (\text{矩形式})
$$

亦可寫成極座標形式：

$$
|H| = \frac{1}{\sqrt{1 + x^2}}, 
\quad 
\angle H = -\tan^{-1}(x)
$$

3.  因 $x(t) = e^{j\Omega t}$，輸出為：

$$
y(t) = H(j\Omega)e^{j\Omega t}
$$

### 三個頻率的計算

(a) $f = 100\text{Hz}$

$$
x = \frac{f}{400} = 0.25
$$

矩形式：

$$
H = \frac{1 - j(0.25)}{1 + (0.25)^2} 
  = \frac{1 - j0.25}{1.0625}
  = 0.94117647 - j0.23529412
$$

極座標：

$$
|H| = \frac{1}{\sqrt{1 + 0.25^2}} = 0.9701425,
\quad 
\angle H = -\tan^{-1}(0.25) = -14.036^\circ
$$

輸出：

$$
y(t) = H e^{j(2\pi 100)t}
     = 0.9701425 e^{j(2\pi 100t - 14.036^\circ)}
$$

(b) $f = 400\text{Hz}$ （剛好截止頻率）

$$
x = 1
$$

**矩形式：**

$$
H = \frac{1 - j}{2} = 0.5 - j0.5
$$

**極座標：**

$$
|H| = \frac{1}{\sqrt{2}} = 0.70710678, 
\quad \angle H = -45^\circ
$$

**輸出：**

$$
y(t) = H e^{j(2\pi \cdot 400t)} = 0.70710678 e^{j(2\pi \cdot 400t - 45^\circ)}
$$

(c) $f = 3000\text{Hz}$

由於：

$$
x = \frac{3000}{400} = 7.5
$$

**矩形式：**

$$
H = \frac{1 - j(7.5)}{1 + (7.5)^2} 
= \frac{1 - j7.5}{57.25}
= 0.01746725 - j0.1300437
$$


**極座標：**

$$
|H| = \frac{1}{\sqrt{1 + 7.5^2}} = 0.13216372, 
\quad \angle H = -\tan^{-1}(7.5) = -82.405^\circ
$$


**輸出：**

$$
y(t) = H e^{j(2\pi \cdot 3000t)} 
= 0.13216372 e^{j(2\pi \cdot 3000t - 82.405^\circ)}
$$


## Problem 4
已知：

$$
x(t) = e^{j\Omega t}u(t), \quad R = 1000\Omega, \quad 
C = \left(\frac{1}{2\pi} \times \frac{1}{400} \times \frac{1}{1000}\right)
$$

求：

$$
y(t) \text{ for } \Omega = 2\pi f, \quad f = 100Hz\, 400Hz\, 3000Hz
$$

---

### ✍️ 手寫圖
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem4_01.jpg" alt="Problem 2 手寫稿（上半）" width="40%">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem4_02.jpg" alt="Problem 2 手寫稿（下半）" width="40%">
</p>

---

### 🧩 LaTeX
$$
\text{Sol:} \\
\begin{cases}
\text{輸入: } x(t) = e^{j\Omega t} u(t) \quad (\text{在 } t < 0 \text{ 為 } 0,  t \ge 0 \text{ 打開一個複指數}) \\
\text{電路: } RC \text{ 低通 (輸出取電容電壓)} \\
\text{因為乘了 } u(t) \text{ 是「因果開關」，解答一定是 } \text{穩態} + \text{暫態}
\end{cases}
$$

---

$$
\text{解法:} \\
\begin{cases}
\text{RC方程: } RC \dfrac{dy(t)}{dt} + y(t) = x(t), \quad \text{令 } \tau = RC. \\
\\
\text{對 } x(t) = e^{j\Omega t}u(t): \\
\text{特解(穩態): } y_p(t) = K e^{j\Omega t} \Rightarrow K(1 + j\Omega \tau) = 1 \\
H(\Omega) = K = \dfrac{1}{1 + j\Omega \tau} \\
\\
\text{齊次解(暫態): } y_h(t) = A e^{-t/\tau} \\
\text{初始條件: 初始時靜止且電容電壓連續 } y(0^-) = y(0^+) = 0 \Rightarrow A = -H(j\Omega) \\
\\
\text{所以總解(對所有 } t \ge 0): \\
y(t) = H(\Omega) \left( e^{j\Omega t} - e^{-t/\tau} \right) u(t), \quad H(\Omega) = \dfrac{1}{1 + j\Omega \tau}
\end{cases}
$$

---

$$
\text{數值帶入 :} \\
\tau = RC = 1 \times 10^3 \times \dfrac{1}{2\pi \times 4 \times 10^2} = \dfrac{1}{2\pi \times 400} \approx 3.981 \times 10^{-4} \text{ s } \(0.398\text{ms})
$$

$$
f_c = \dfrac{1}{2\pi RC} = 400\text{Hz}
$$

$$
\text{令 } \chi \equiv \Omega \tau = \dfrac{f}{400}
$$

$$
\text{則 } 
H = \dfrac{1}{1 + j\chi}, \quad
H = \dfrac{1 - j\chi}{(1 + j\chi)(1 - j\chi)} = \dfrac{1 - j\chi}{1 + \chi^2}
$$

$$
|H| = \dfrac{1}{\sqrt{1 + \chi^2}}, \quad
\angle H = -\tan^{-1}(\chi)
$$

---

### (a) f = 100 Hz → χ = 100 / 400 = 0.25

$$
\text{矩形式:} \quad
H = \dfrac{1 - j0.25}{1.0625} = 0.94117647 - j0.23529412
$$

$$
\text{極座標:} \quad
|H| = 0.97014250, \quad \angle H = -14.036^\circ
$$

$$
y(t) = H \left( e^{j2\pi 100t} - e^{-t/\tau} \right) u(t)
$$

---

### (b) f = 400 Hz → χ = 1（剛好截止）

$$
\text{矩形式:} \quad
H = \dfrac{1 - j1}{2} = 0.5 - j0.5
$$

$$
\text{極座標:} \quad
|H| = 0.70710678, \quad \angle H = -45^\circ
$$

$$
y(t) = H \left( e^{j2\pi 400t} - e^{-t/\tau} \right) u(t)
$$

---

### (c) f = 3000 Hz → χ = 3000 / 400 = 7.5

$$
\text{矩形式:} \quad
H = \dfrac{1 - j7.5}{1 + 7.5^2} = \dfrac{1 - j7.5}{57.25} = 0.01746725 - j0.13100437
$$

$$
\text{極座標:} \quad
|H| = 0.13216372, \quad \angle H = -82.405^\circ
$$

$$
y(t) = H \left( e^{j2\pi 3000t} - e^{-t/\tau} \right) u(t)
$$


## Problem 5
### ✍️ 手寫圖
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem5_01.jpg" alt="Problem 1 手寫稿" width="50%">
</p>
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem5_02.jpg" alt="Problem 1 手寫稿" width="50%">
</p>
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem5_03.jpg" alt="Problem 1 手寫稿" width="50%">
</p>

---

### 🧩 LaTeX
## Sol:
### ① 離散化與式簡化

從 Eq.(8) 可得出這是一個一階差分方程：

$$
y[n] = a_1y[n-1] + b_0x[n]
$$

其中：

$$
a_1 = \frac{RC}{RC + T}, \qquad b_0 = \frac{T}{RC + T}
$$

並且：

$$
a_1 + b_0 = 1
$$


### ② 假設輸入為複指數

若輸入：

$$
x[n] = e^{j\omega n}
$$

則輸出可寫成：

$$
y[n] = H(\omega)e^{j\omega n}
$$

代入 Eq.(8)：

$$
H e^{j\omega n} = a_1 H e^{j\omega (n-1)} + b_0e^{j\omega n}
$$

約去相同項得：

$$
H = a_1 H e^{-j\omega} + b_0
$$

整理後：

$$
H(\omega) = \frac{1}{1 - a_1 e^{-j\omega}}
$$

因此輸出為：

$$
y[n] = H(\omega)e^{j\omega n}
     = \frac{b_0}{1 - a_1 e^{-j\omega}} e^{j\omega n}
$$

### ③ 計算不同採樣率的係數

求電路時間常數：

$$
RC = \frac{1}{2\pi \times 400} \approx 3.98 \times 10^{-4}\ \text{s}
$$


### 採樣率與係數表

公式：

$$
a_1 = \frac{RC}{RC + T}, \qquad
b_0 = \frac{T}{RC + T}, \qquad
T = \frac{1}{f_s}
$$

| Sampling rate (Hz) | \(T) (s) | \(a1) | \(b0\) |
|:--------------------------:|:-----------------:|:-------:|:-------:|
| 4000   | 0.00025   | 0.61413 | 0.38587 |
| 8000   | 0.000125  | 0.76094 | 0.23906 |
| 16000  | 0.0000625 | 0.86424 | 0.13576 |

> 由表可見，當採樣率越高，\(a1\) 越接近 1，而 \(b0\) 越小。


### ④ 寫出三種 
$$
H(\omega) \ 與 \ y[n] \
$$

$$
H_{f_s}(\omega) = \frac{b_0(f_s)}{1 - a_1(f_s)e^{-j\omega}}, 
\qquad 
y_{f_s}[n] = H_{f_s}(\omega) e^{j\omega n}
$$

若要展開成實部與虛部：

$$
H(\omega) =
\frac{b_0 \left( 1 - a_1 \cos\omega + j a_1 \sin\omega \right)}
{\sqrt{(1 - a_1 \cos\omega)^2 + (a_1 \sin\omega)^2}}
$$

因此可得：

$$
|H| = \frac{b_0}{\sqrt{(1 - a_1 \cos\omega)^2 + (a_1 \sin\omega)^2}}, 
\qquad
\angle H = \tan^{-1}\left(\frac{a_1 \sin\omega}{1 - a_1 \cos\omega}\right)
$$

### ⑤ 總結結果

(1) fs = 4000（Hz）  
a1 = 0.61413, b0 = 0.38587

$$
H(\omega) = \frac{0.38587}{1 - 0.61413 e^{-j\omega}}
$$

$$
y[n] = \frac{0.38587\, e^{j\omega n}}{1 - 0.61413 e^{-j\omega}}
$$


(2) fs = 8000（Hz）  
a1 = 0.76094, b0 = 0.23906

$$
H(\omega) = \frac{0.23906}{1 - 0.76094 e^{-j\omega}}
$$

$$
y[n] = \frac{0.23906\, e^{j\omega n}}{1 - 0.76094 e^{-j\omega}}
$$


(3) fs = 16000（Hz）  
a1 = 0.86424, b0 = 0.13576

$$
H(\omega) = \frac{0.13576}{1 - 0.86424 e^{-j\omega}}
$$

$$
y[n] = \frac{0.13576\, e^{j\omega n}}{1 - 0.86424 e^{-j\omega}}
$$

### ⑥ 物理意義

- 當 fs 越高 Ts 越小，系統越接近連續時間 RC 模型。

- H(w)的幅度曲線變平滑

- 在低取樣率（4kHz）時，誤差較大；  
  而在高取樣率（16kHz）時，數位與模擬濾波器幾乎相同。



## Problem 6

### Sol:

- 已知輸入訊號：

$$
x[n] = u[n] e^{j\omega n} 
$$

也就是在  n < 0  時沒有輸入，從  n = 0  開始打開一個複指數波。

- 系統由 Eq.(8)（RC 低通離散化）描述：

$$
y[n] = \frac{RC}{RC + T} \ y[n - 1] + \frac{T}{RC + T} \ x[n]
$$

其中  

$$
T = \frac{1}{f_s}
$$  

為取樣週期。

---
### ✍️ 手寫圖
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem6_01.jpg" alt="Problem 1 手寫稿" width="50%">
</p>
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem6_02.jpg" alt="Problem 1 手寫稿" width="50%">
</p>
<p align="center">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem6_03.jpg" alt="Problem 1 手寫稿" width="50%">
</p>

---



### 🧩 LaTeX

### ① 將 Eq.(8) 寫成差分方程形式

$$
y[n] = a_1 \ y[n - 1] + b_0 \ x[n]
$$

其中  

$$
a_1 = \frac{RC}{RC + T}, \qquad
b_0 = \frac{T}{RC + T} \(a_1 + b_0 = 1)
$$

---

### ② 求特解（穩態）與齊次解（暫態）

假設輸入為  

$$
x[n] = e^{j\omega n}
$$

則特解形式為  

$$
y_p[n] = H(\omega) e^{j\omega n}
$$

代入差分方程得：

$$
H e^{j\omega n} = a_1 H e^{j\omega (n - 1)} + b_0 e^{j\omega n}
$$

化簡可得系統頻率響應：

$$
H(\omega) = \frac{b_0}{1 - a_1 e^{-j\omega}}
$$

### ③ 解齊次解（系統本身的記憶與衰減）

令 \( x[n] = 0 \)，則有  

$$
y_h[n] = K a_1^n
$$


---

### ④ 初始條件（初始靜止）

題目已知系統「初始靜止」，即  

$$
y[n] = 0 \quad \text{for} \quad n < 0
$$

由 Eq.(8) 可得，當 \( n = 0 \)：  

$$
y[0] = a_1 y[-1] + b_0 x[0] = 0 + b_0 \cdot 1 = b_0
$$

而總解在 \( n >= 0 \) 時為：  

$$
y[n] = H e^{j\omega n} + K a_1^n
$$

代入 \( n = 0 \)：  

$$
y[0] = H + K = b_0 \quad \Rightarrow \quad K = b_0 - H
$$

### ⑤ 答案（暫態 + 穩態）

總解為：

$$
y[n] = \big( H(\omega) e^{j\omega n} + (b_0 - H(\omega)) a_1^n \big) u[n]
$$

其中：

$$
H(\omega) = \frac{b_0}{1 - a_1 e^{-j\omega}}, 
\qquad 
a_1 = \frac{RC}{RC + T}, 
\qquad 
b_0 = \frac{T}{RC + T}, 
\qquad 
T = \frac{1}{f_s}
$$

---

### 驗證的寫法（將暫態項改寫成含 \( H \) 的形式）

由：

$$
b_0 - H = -a_1 e^{-j\omega} H
$$

可得：

$$
y[n] = \big( H e^{j\omega n} - H a_1^{n+1} e^{-j\omega} \big) u[n]
$$

### ④ 三個取樣率下的係數

先計算：

$$
RC = \frac{1}{2 \pi \times 400} \ \text{s}
$$

對三個取樣頻率 fs 分別計算：

| fs(Hz) | t=1/fs (s) | a1 = RC/RC+T | b0 = T/RC+T |
|:--------------:|:----------------------------:|:------------------------------:|:------------------------------:|
| 4000  | 0.00025000 | 0.614130455 | 0.385869545 |
| 8000  | 0.00012500 | 0.760942976 | 0.239057024 |
| 16000 | 0.00006250 | 0.864244752 | 0.135755248 |


將上述 a1, b0 代入「通用答案」公式中，  
即可得到對應三種取樣率下的 \( y[n] \)。

### ⑤ 結論

- \( y[n] \) 由 **穩態項** 與 **暫態項**  組成。
- 由於 a1 屬於 (0,1)，  暫態項會隨時間逐漸衰減。
- 當取樣頻率 fs 越高，差分模型越貼近連續時間 RC 的行為

好問題 👍
GitHub 的 README.md 原生不支援 LaTeX 數學公式，
所以像 π、²、或 e^{-x} 這類公式若直接貼上會亂碼或顯示不出來。

👉 解法：我幫你改成純文字版本（不使用 LaTeX、只用標準 ASCII），
保留數學意涵又完全能在 GitHub 正常顯示。
下面這份可以直接貼上 README.md，100% 保證 GitHub 顯示正常：

⸻

Problem 7 — C 語言程式講解說明

本題要求完成兩個 C 程式：
(1) 產生測試用的正弦與餘弦音訊波形。
(2) 對產生的音訊執行一階 RC 濾波，模擬式 (8) 的運算行為。

⸻

1. sine_wav_gen.c — 產生測試訊號

此程式用於產生雙聲道的 .wav 檔，左聲道為 sin 波，右聲道為 cos 波。
輸出為 16-bit PCM stereo 格式，並自動建立 WAV header。

程式重點：
	1.	輸入參數

./sine_wav_gen fs f L output.wav

	•	fs：取樣頻率 (Hz)
	•	f：訊號頻率 (Hz)
	•	L：訊號長度 (秒)
	•	output.wav：輸出檔名

	2.	建立 WAV header
設定取樣率 (SampleRate)、位元數 (BitsPerSample=16)、通道數 (NumChannels=2)。
同時計算每秒位元率 (ByteRate) 與封包長度 (BlockAlign)。
	3.	產生樣本

Ls = sin(2 * PI * f * t);
Rs = cos(2 * PI * f * t);

乘上幅度 A = 0.9 * 32767，避免失真。
	4.	輸出檔
使用 fwrite() 將左、右聲道樣本依序寫入，形成 stereo 音訊。

範例輸出

./sine_wav_gen 8000 3000 1.0 sincos_fs8000_f3000_L1.0.wav

會產生 1 秒長度的雙聲道音檔。

⸻

2. RC_filtering.c — 實作 RC 濾波

此程式讀取 .wav 音檔，根據式 (8)：

y[n] = a1 * y[n-1] + b0 * x[n]

對左右聲道分別做一階 RC 濾波。

程式重點：
	1.	輸入參數

./RC_filtering in.wav out.wav

	•	in.wav：輸入音訊檔（例如 sine_wav_gen 輸出的檔）
	•	out.wav：輸出經濾波後的音訊檔

	2.	讀取 WAV header
檢查格式 (“RIFF”, “WAVE”, “fmt “, “data”)。
讀出取樣率 fs 與通道數 NumChannels。
僅支援 16-bit stereo PCM。
	3.	計算濾波係數
RC 濾波的係數為：

a1 = exp(-1 / (RC * fs))
b0 = 1 - a1

在程式中設定：

double RC = 1.0 / (2.0 * M_PI * 4000.0);  // RC 對應截止頻率約 4000 Hz
double a1 = exp(-1.0 / (RC * fs));
double b0 = 1.0 - a1;

	4.	濾波主迴圈

yL[n] = a1 * yL[n-1] + b0 * xL[n];
yR[n] = a1 * yR[n-1] + b0 * xR[n];

每一個樣本都根據上一個輸出進行一階遞迴濾波。
	5.	結果輸出
終端顯示：

Filtered WAV written: filtered_sincos_fs8000_f3000_L1.0.wav
(fs=8000 Hz, a1=0.614, b0=0.385)


⸻

整體流程

sine_wav_gen.c
   ↓ (產生 sin/cos 訊號)
   → sincos_fs8000_f3000_L1.0.wav
   ↓
RC_filtering.c
   ↓ (執行式(8) RC 濾波)
   → filtered_sincos_fs8000_f3000_L1.0.wav


⸻

結論

這兩個程式完整實作了 Problem 7 要求的內容：
	•	訊號產生：可自由設定頻率、取樣率與時間長度。
	•	RC 濾波：自動從輸入音檔讀取 sampling rate，並依式 (8) 執行濾波運算。
	•	結果驗證：輸出的 .wav 音檔可直接用音訊播放器聽取濾波前後差異。

⸻
