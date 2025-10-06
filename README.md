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


