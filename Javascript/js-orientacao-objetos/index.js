import { Cliente } from "./Cliente.js";
import { Gerente } from "./Funcionario/Gerente.js";
import { Diretor } from "./Funcionario/Diretor.js";
import { SistemaAutenticacao } from "./SistemaAutenticacao.js";

const diretor = new Diretor("Mario", 10000, 1234567890);
diretor.cadastrarSenha("123456");
const gerente = new Gerente("Joao", 5000, 9876543210);
diretor.cadastrarSenha("1234");

const cliente = new Cliente("Lais", 789123460, "456");

const gerenteEstaLogado = SistemaAutenticacao.login(gerente, "1234");
const diretorEstaLogado = SistemaAutenticacao.login(diretor, "123456");

const clienteEstaLogado = SistemaAutenticacao.login(cliente, "456");

console.log(gerenteEstaLogado, diretorEstaLogado, clienteEstaLogado);
