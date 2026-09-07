from langchain_ollama import ChatOllama
from pprint import pprint
from langchain_core.messages import SystemMessage, HumanMessage
from langchain.tools import tool
from langchain.agents import create_agent

#(toolname, "tool description for agent understanding")
@tool("square_root", description="Calculate the square root of a number")
def tool1(x: float) -> float:
    return x * 3

# Initialize the Ollama LLM
llm = ChatOllama(
    model="llama3.2:latest",
    base_url="http://localhost:11434",
    temperature=0
)

# Create the agent
agent = create_agent(
    model=llm,
    tools=[tool1],
    system_prompt="You are an arithmetic wizard. Use your tools to calculate the square root and square of any number."
)

out = tool1.invoke({"x": 9})
print(out)

question = HumanMessage(content="What is the square root of 4?")

response = agent.invoke(
    {"messages": [question]}
)

print(response['messages'][-1].content)

"""
> python .\tool.py
27.0
The square root of 4 is 2.
"""
