library(ggcorrplot)
library(ggplot2)
library(tidyverse)

data <- read.csv("tfg.csv", header=TRUE, stringsAsFactors=TRUE)

data <- data %>%
  mutate(Name = as.character(Name))

str(data)
summary(data)

numeric_data <- data %>%
  select(Characters, NonWhitespaceCharacters, Lines, Tokens)

corr_matrix <- cor(numeric_data)

print(
  ggcorrplot(corr_matrix, 
           method = "square",
           type = "lower",
           lab = TRUE,
           colors = c("red", "white", "blue"),
           title = "Matriz de Correlación",
           lab_size = 4) +
  labs(
    title = "Matriz de Correlación",
    x = "",
    y = ""
  ) +
  theme_minimal(base_size = 16)
)

filtered_data <- count(
  data,
  Language,
  Category,
  name="Frequency"
)

print(
  ggplot(filtered_data, aes(Category, Frequency, fill = Language)) +
    geom_col(position = "dodge") +
    labs(
      title = "Frecuencia por Categoría y Lenguaje",
      x = "Categoría",
      y = "Frecuencia",
      fill = "Lenguaje"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Characters, Lines, color = Language)) +
    geom_point() +
    labs(
      title = "Distribución de Caracteres y Lineas por Lenguaje",
      x = "Caracteres",
      y = "Lineas",
      color = "Lenguaje"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Language, Characters, fill = Language)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Caracteres por Lenguaje",
      x = "Lenguaje",
      y = "Caracteres",
      fill = "Lenguaje"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

print(
  ggplot(data, aes(Language, NonWhitespaceCharacters, fill = Language)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Caracteres no Blancos por Lenguaje",
      x = "Lenguaje",
      y = "Caracteres no Blancos",
      fill = "Lenguaje"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

print(
  ggplot(data, aes(Language, Lines, fill = Language)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Lineas por Lenguaje",
      x = "Lenguaje",
      y = "Lineas",
      fill = "Lenguaje"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

print(
  ggplot(data, aes(Characters, Lines, color = Category)) +
    geom_point() +
    labs(
      title = "Distribución de Caracteres y Lineas por Categoría",
      x = "Caracteres",
      y = "Líneas",
      color = "Categoría"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Category, Characters, fill = Category)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Caracteres por Categoría",
      x = "Categoría",
      y = "Caracteres",
      fill = "Categoría"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

print(
  ggplot(data, aes(Category, NonWhitespaceCharacters, fill = Category)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Caracteres no Blancos por Categoría",
      x = "Categoría",
      y = "Caracteres no Blancos",
      fill = "Categoría"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

print(
  ggplot(data, aes(Category, Lines, fill = Category)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Lineas por Categoría",
      x = "Categoría",
      y = "Lineas",
      fill = "Categoría"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

print(
  ggplot(data, aes(Language, Tokens, fill = Language)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Tokens por Lenguaje",
      x = "Lenguaje",
      y = "Tokens",
      fill = "Lenguaje"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

summary_data <- data %>%
  select(Category, AverageTokenLength, SDTokenLength) %>%
  group_by(Category) %>%
  summarise(
    Mean = mean(AverageTokenLength),
    SD = mean(SDTokenLength)
  )

print(
  ggplot(summary_data, aes(x = Category, y = Mean, fill = Category)) +
    geom_col() +
    geom_errorbar(aes(ymin = Mean - SD, ymax = Mean + SD), width = 0.2) +
    labs(
      title = "Distribución de Tokens por Categoría",
      x = "Categoría",
      y = "Tamaño de Token",
      fill = "Categoría"
    ) +
    theme_minimal() +
    theme(legend.position = "none")
)

df_summary_by_cat_lang <- data %>%
  group_by(Category, Language) %>%
  summarise(
    avg_Characters = mean(Characters),
    avg_NonWhitespace = mean(NonWhitespaceCharacters),
    avg_Lines = mean(Lines),
    avg_Tokens = mean(Tokens),
    .groups = "drop"
  )

print(
  ggplot(df_summary_by_cat_lang, aes(Category, avg_Characters, fill = Language)) +
    geom_col(position = "dodge") +
    labs(title = "Media de Caracteres por Categoría y Lenguaje",
         x = "Categoría", y = "Media de Caracteres", fill = "Lenguaje") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(Category, avg_NonWhitespace, fill = Language)) +
    geom_col(position = "dodge") +
    labs(title = "Media de Caracteres no Blancos por Categoría y Lenguaje",
         x = "Categoría", y = "Media de Caracteres no Blancos", fill = "Lenguaje") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(Category, avg_Lines, fill = Language)) +
    geom_col(position = "dodge") +
    labs(title = "Media de Lineas por Categoría y Lenguaje",
         x = "Categoría", y = "Media de Lineas", fill = "Lenguaje") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(Category, avg_Tokens, fill = Language)) +
    geom_col(position = "dodge") +
    labs(title = "Media de Tokens por Categoría y Lenguaje",
         x = "Categoría", y = "Media de Tokens", fill = "Lenguaje") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_Characters)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Media de Caracteres por Categoría y Lenguaje",
         x = "Lenguaje", y = "Categoría", fill = "Media de Caracteres")
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_NonWhitespace)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Media de Caracteres no Blancos por Categoría y Lenguaje",
         x = "Lenguaje", y = "Categoría", fill = "Media de Caracteres no Blancos")
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_Lines)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Media de Lineas por Categoría y Lenguaje",
         x = "Lenguaje", y = "Categoría", fill = "Media de Lineas")
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_Tokens)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Media de Tokens por Categoría y Lenguaje",
         x = "Lenguaje", y = "Categoría", fill = "Media de Tokens")
)

str(df_summary_by_cat_lang)
summary(df_summary_by_cat_lang)

best_language_per_category <- df_summary_by_cat_lang %>%
  group_by(Category) %>%
  slice_min(avg_Characters)

print(
  ggplot(best_language_per_category, aes(x = reorder(Category, avg_Characters), y = avg_Characters, fill = Language)) +
    geom_bar(stat = "identity") +
    coord_flip() +
    theme_minimal() +
    labs(
      title = "Mejor Lenguaje por Categoría",
      x = "Categoría",
      y = "Media de Caracteres",
      fill = "Lenguaje"
    ) +
    theme(legend.position = "top")
)

print(best_language_per_category)

library(car)
print(leveneTest(Characters ~ Language, data = data))

print(kruskal.test(Characters ~ Language, data = data))

library(FSA)
resultado <- dunnTest(Characters ~ Language, data = data, method = "bonferroni")

library(knitr)
print(kable(resultado$res, digits = 5, caption = "Resultados del Test de Dunn (Bonferroni)"))
