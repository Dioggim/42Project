# Fract'ol 🌀

Este projeto é parte do currículo da 42, focado na criação de um visualizador de fractais interativo usando a biblioteca MinilibX. O programa permite explorar diferentes tipos de fractais com esquemas de cores dinâmicos.

## 📋 Sumário
1. [Sobre o Projeto](#sobre-o-projeto)
2. [Requisitos](#requisitos)
3. [Instalação](#instalação)
4. [Como Usar](#como-usar)
5. [Funcionalidades](#funcionalidades)
6. [Detalhes Técnicos](#detalhes-técnicos)
7. [Autor](#autor)

## 🔍 Sobre o Projeto

O Fract'ol é um programa que gera visualizações de fractais matemáticos, incluindo:

- **Conjunto de Mandelbrot**: z = z² + c
- **Conjunto de Julia**: Variação do Mandelbrot com c constante
- **Burning Ship**: Variação que usa valores absolutos

Cada fractal pode ser explorado com:
- Zoom infinito (limitado apenas pela precisão do double)
- Esquemas de cores dinâmicos
- Navegação intuitiva
- Renderização em tempo real

## 💻 Requisitos

- Sistema operacional Linux
- Biblioteca X11
- GCC
- Make

## 🛠️ Instalação

1. Clone o repositório:
```bash
git clone https://github.com/diogodiaz/fractol.git
cd fractol
```

2. Compile o projeto:
```bash
make
```

## 🎮 Como Usar

Execute o programa especificando o tipo de fractal:
```bash
./fractol mandelbrot    # Visualiza o conjunto de Mandelbrot
./fractol julia        # Visualiza o conjunto de Julia
./fractol ship         # Visualiza o Burning Ship
```

### Controles

| Tecla/Ação | Função |
|------------|--------|
| Mouse Scroll Up | Zoom in na posição do cursor |
| Mouse Scroll Down | Zoom out |
| Setas | Movimentação pelo fractal |
| ESC | Sair do programa |
| C | Alternar esquema de cores |
| +/- | Ajustar zoom |

## 🎨 Funcionalidades

### Sistema de Cores
O programa implementa um sistema de cores dinâmico baseado em funções trigonométricas:

```c
// Exemplo de cálculo de cores
intensity = 1.0 - (0.7 * t);
rainbow = 6.28318530718 * t;
rgb[0] = intensity * (127 * sin(rainbow) + 128);
rgb[1] = intensity * (127 * sin(rainbow + 2.0944) + 128);
rgb[2] = intensity * (127 * sin(rainbow + 4.18879) + 128);
```

### Otimizações
- Cálculos vetorizados
- Gerenciamento eficiente de memória
- Renderização otimizada

## 🔧 Detalhes Técnicos

### Estrutura do Projeto
```
fractol/
├── includes/
│   └── fractol.h     # Definições e estruturas
├── src/
│   ├── main.c        # Entrada do programa
│   ├── color.c       # Sistema de cores
│   ├── events.c      # Eventos de input
│   ├── fractals.c    # Cálculos dos fractais
│   ├── move.c        # Movimentação
│   ├── zoom.c        # Sistema de zoom
│   └── utils.c       # Funções utilitárias
└── Makefile
```

### Performance
- Uso de otimizações matemáticas
- Buffer de pixels para renderização rápida
- Cálculos precisos com números complexos

## 👤 Autor

**Diogo Gimenez**
- 42 Login: dgimenez
- GitHub: [@diogodiaz](https://github.com/diogodiaz)

## 📝 Notas

Para melhor experiência:
- Explore diferentes áreas do fractal com o zoom
- Experimente diferentes esquemas de cores
- No conjunto Julia, observe como pequenas mudanças afetam todo o padrão

---
Projeto desenvolvido como parte do currículo da [42](https://www.42.fr/).
```c
// Combina os canais RGB em um único valor
return ((r << 16) | (g << 8) | b);
```

### Dica de Debug:
Para visualizar como cada componente de cor se comporta, você pode usar:
```c
printf("RGB(%d, %d, %d) at t=%.3f\n", r, g, b, t);
```

## 🔍 Sistema de Zoom e Eventos

### Zoom System (Debug Guide)

1. **Estrutura do Zoom**:
```c
// Função de zoom in (events.c)
static void zoom_in(t_data *data, double mouse_re, double mouse_im, double *range)
{
    // Reduz a área de visualização pela metade
    data->min_x = mouse_re - (range[0] * 0.5 * 0.5);
    data->max_x = mouse_re + (range[0] * 0.5 * 0.5);
    data->min_y = mouse_im - (range[1] * 0.5 * 0.5);
    data->max_y = mouse_im + (range[1] * 0.5 * 0.5);
}

// Função de zoom out (events.c)
static void zoom_out(t_data *data, double mouse_re, double mouse_im, double *range)
{
    // Aumenta a área de visualização pelo dobro
    data->min_x = mouse_re - (range[0] * 0.5 * 2.0);
    data->max_x = mouse_re + (range[0] * 0.5 * 2.0);
    data->min_y = mouse_im - (range[1] * 0.5 * 2.0);
    data->max_y = mouse_im + (range[1] * 0.5 * 2.0);
}
```

2. **Manipulação de Eventos**:
```c
// Movimentação com teclado (events.c)
static void move_view(t_data *data, double range_x, double range_y, int dir)
{
    if (dir == KEY_LEFT)
    {
        // Move 10% da tela para a esquerda
        data->min_x -= range_x * 0.1;
        data->max_x -= range_x * 0.1;
    }
    // ... outras direções
}

// Zoom com teclado (events.c)
static void key_zoom(t_data *data, double range_x, double range_y, int zoom_in)
{
    if (zoom_in)
    {
        // Reduz a área de visualização em 10%
        data->min_x += range_x * 0.1;
        data->max_x -= range_x * 0.1;
        data->min_y += range_y * 0.1;
        data->max_y -= range_y * 0.1;
    }
    // ... zoom out
}
```

### Debug Tips:

1. **Verificando Coordenadas**:
```c
// Adicione em pontos críticos para debug
printf("Mouse: (%d, %d) -> Complex: (%.3f, %.3f)\n",
    x, y, mouse_re, mouse_im);
printf("View: (%.3f, %.3f) to (%.3f, %.3f)\n",
    data->min_x, data->min_y, data->max_x, data->max_y);
```

2. **Monitorando Iterações**:
```c
// Em calculate_pixel
int iter = mandelbrot_iteration(c, data->max_iter);
printf("Pixel(%d, %d): %d iterations\n", x, y, iter);
```

3. **Verificando Performance**:
```c
// No início de draw_fractal
clock_t start = clock();
// ... desenho do fractal
clock_t end = clock();
double cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Frame time: %.3f seconds\n", cpu_time);
```

## 🔧 Otimizações

1. **Cálculo de Cores**:
- As cores são pré-calculadas para cada nível de iteração
- Funções trigonométricas são otimizadas para máxima suavidade
- Transições suaves entre esquemas de cores

2. **Renderização**:
- Uso de buffer de imagem para desenho eficiente
- Acesso direto à memória de pixels
- Otimização de loops de renderização

3. **Interatividade**:
- Sistema de eventos não-bloqueante
- Zoom suave e responsivo
- Controles intuitivos

4. **Multi-threading**: Para melhor performance, você pode dividir o cálculo em threads:
```c
#include <pthread.h>

void *calculate_region(void *arg)
{
    t_thread_data *tdata = (t_thread_data *)arg;
    // Calcular uma região específica da imagem
    return NULL;
}
```

## 🚀 Próximos Passos

Algumas ideias para expandir o projeto:
- Adicionar mais tipos de fractais (Sierpinski, Phoenix, etc.)
- Implementar salvamento de imagens
- Adicionar animações nos parâmetros do Julia
- Implementar multi-threading para melhor performance

## 📚 Recursos

- [Fractais - Wikipedia](https://en.wikipedia.org/wiki/Fractal)
- [Conjunto de Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Conjunto de Julia](https://en.wikipedia.org/wiki/Julia_set)

## 🤝 Contribuindo

Sinta-se à vontade para fazer um fork e enviar pull requests com melhorias!
