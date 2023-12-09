import matplotlib.pyplot as plt


def get_plot(title: str, name: str) -> None:
    # Sample data
    categories = ['GitHub Copilot', 'Tabnine', 'ChatGPT', 'CodeGeeX']
    tool1_data = [20, 35, 25, 30]
    tool2_data = [15, 25, 30, 20]
    tool3_data = [10, 15, 20, 25]

    # Plotting the stacked bar chart
    fig, ax = plt.subplots()

    fontsize='large'

    # Prompt from SecurityEval
    # CWE prompt
    # Prompt with vulnerability warning
    bar1 = ax.bar(categories, tool1_data, label='M1')
    bar2 = ax.bar(categories, tool2_data, bottom=tool1_data, label='M2')
    bar3 = ax.bar(categories, tool3_data, bottom=[i + j for i, j in zip(tool1_data, tool2_data)], label='M3')

    # Adding values in the middle of each bar
    def add_values_in_middle(bars):
        for bar in bars:
            for rect in bar:
                height = rect.get_height()
                ax.text(rect.get_x() + rect.get_width() / 2, height / 2 + rect.get_y(),
                        '{}%'.format(height), ha='center', va='center', fontsize=fontsize)

    add_values_in_middle([bar1, bar2, bar3])

    # Adding labels and title
    ax.set_ylabel('Percentage of programs containing vulnerabilities', fontsize=fontsize)
    ax.set_xlabel('Tool', fontsize=fontsize)
    ax.set_title(title, fontsize=fontsize)
    ax.legend()

    # Setting xticks and yticks with specified font size
    ax.tick_params(axis='x', labelsize=fontsize)
    ax.tick_params(axis='y', labelsize=fontsize)

    # Show the plot
    # plt.show()
    plt.gcf().set_size_inches(14, 7)
    plt.savefig(f'figures/{name}', dpi=200)

titles = ['RQ1 Python vulnerablity analysis', 'RQ2 C\C++ vulnerablity analysis',
          'RQ3 C# vulnerablity analysis', 'RQ4 Js/Ts vulnerablity analysis']

names = ['rq1_figure1.png', 'rq2_figure1.png', 'rq3_figure1.png', 'rq4_figure1.png']

for title, names in zip(titles, names):
    get_plot(title, names)