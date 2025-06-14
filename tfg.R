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
           title = "Correlation Matrix",
           lab_size = 3) +
  labs(
    title = "Correlation Matrix",
    x = "",
    y = ""
  ) +
  theme_minimal()
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
      title = "Frecuencia por Category",
      x = "Category",
      y = "Frecuencia"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Characters, Lines, color = Language)) +
    geom_point() +
    labs(
      title = "Distribución de Characters y Lines por Language",
      x = "Characters",
      y = "Lines"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Language, Characters, fill = Language)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Characters por Language",
      x = "Language",
      y = "Characters"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Language, NonWhitespaceCharacters, fill = Language)) +
    geom_boxplot() +
    labs(
      title = "Distribución de NonWhitespaceCharacters por Language",
      x = "Language",
      y = "NonWhitespaceCharacters"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Language, Lines, fill = Language)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Lines por Language",
      x = "Language",
      y = "Lines"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Characters, Lines, color = Category)) +
    geom_point() +
    labs(
      title = "Distribución de Characters y Lines por Category",
      x = "Characters",
      y = "Lines"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Category, Characters, fill = Category)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Characters por Category",
      x = "Category",
      y = "Characters"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Category, NonWhitespaceCharacters, fill = Category)) +
    geom_boxplot() +
    labs(
      title = "Distribución de NonWhitespaceCharacters por Category",
      x = "Category",
      y = "NonWhitespaceCharacters"
    ) +
    theme_minimal()
)

print(
  ggplot(data, aes(Category, Lines, fill = Category)) +
    geom_boxplot() +
    labs(
      title = "Distribución de Lines por Category",
      x = "Category",
      y = "Lines"
    ) +
    theme_minimal()
)

summary_data <- data %>%
  select(Language, AverageTokenLength, SDTokenLength) %>%
  group_by(Language) %>%
  summarise(
    Mean = mean(AverageTokenLength),
    SD = mean(SDTokenLength)
  )

print(
  ggplot(summary_data, aes(x = Language, y = Mean, fill = Language)) +
    geom_col() +
    geom_errorbar(aes(ymin = Mean - SD, ymax = Mean + SD), width = 0.2) +
    labs(
      title = "Mean Token Length with Standard Deviation",
      x = "Language",
      y = "Mean Token Length"
    ) +
    theme_minimal()
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
      title = "Mean Token Length with Standard Deviation",
      x = "Category",
      y = "Mean Token Length"
    ) +
    theme_minimal()
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
    labs(title = "Average Characters by Language and Category",
         y = "Avg Characters") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(Category, avg_NonWhitespace, fill = Language)) +
    geom_col(position = "dodge") +
    labs(title = "Average NonWhitespaceCharacters by Language and Category",
         y = "Avg NonWhitespaceCharacters") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(Category, avg_Lines, fill = Language)) +
    geom_col(position = "dodge") +
    labs(title = "Average Lines by Language and Category",
         y = "Avg Lines") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(Category, avg_Tokens, fill = Language)) +
    geom_col(position = "dodge") +
    labs(title = "Average Tokens by Language and Category",
         y = "Avg Tokens") +
    theme_minimal()
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_Characters)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Heatmap of Avg Characters per Category and Language",
         x = "Language", y = "Category")
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_NonWhitespace)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Heatmap of Avg NonWhitespaceCharacters per Category and Language",
         x = "Language", y = "Category")
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_Lines)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Heatmap of Avg Lines per Category and Language",
         x = "Language", y = "Category")
)

print(
  ggplot(df_summary_by_cat_lang, aes(x = Language, y = Category, fill = avg_Tokens)) +
    geom_tile(color = "white") +
    scale_fill_viridis_c() +
    theme_minimal() +
    labs(title = "Heatmap of Avg Tokens per Category and Language",
         x = "Language", y = "Category")
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
      title = "Best Language per Category (by Shortest Avg Characters)",
      x = "Category",
      y = "Avg Characters"
    ) +
    theme(legend.position = "top")
)

print(best_language_per_category)
