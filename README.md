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
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem2_1.jpg" alt="Problem 2 手寫稿（上半）" width="48%">
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem2_2.jpg" alt="Problem 2 手寫稿（下半）" width="48%">
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
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem2_01.jpg" alt="Problem 2 手寫稿 (上半)" width="40%">
  <br>
  <img src="https://raw.githubusercontent.com/s711383110-tech/Digital-Signal-Processing-Class/main/fig/problem2_02.jpg" alt="Problem 2 手寫稿 (下半)" width="40%">
</p>

---

### 🧩 LaTeX

已知輸入：

$$
x(t)=e^{j\Omega t}u(t)
$$


一階 RC 微分方程式（$\tau=RC$）：

$$
RC\,\frac{dy(t)}{dt}+y(t)=x(t), \qquad \tau=RC
$$


#### ① Particular Solution

設特解：

$$
y_p(t)=K e^{j\Omega t}
$$


代回方程：

$$
\tau \frac{d}{dt}\!\left(K e^{j\Omega t}\right)+K e^{j\Omega t}
= \tau (j\Omega K e^{j\Omega t}) + K e^{j\Omega t}
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


#### ③ 總解（$t\ge 0$）

$$
y(t)=y_p(t)+y_h(t)=H(\Omega)e^{j\Omega t}+A e^{-t/\tau}
$$


#### ④ 初始條件求 $A$

因 $t<0$ 無輸入且電容電壓連續，$y(0^-)=0 \Rightarrow y(0^+)=0$。代 $t=0$：

$$
0=H(\Omega)\cdot 1 + A\cdot 1 \Rightarrow A=-H(\Omega)
$$


#### ⑤ 最終結果（配上有效區間）

$$
y(t)=\Big[\,H(\Omega)e^{j\Omega t}-H(\Omega)e^{-t/\tau}\,\Big]u(t)
= H(\Omega)\,\big(e^{j\Omega t}-e^{-t/\tau}\big)\,u(t)
$$


其中

$$
H(\Omega)=\frac{1}{1+j\Omega\tau}=\frac{1}{1+j\Omega RC}, \qquad \tau=RC.
$$
