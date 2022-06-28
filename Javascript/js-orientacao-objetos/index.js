import { Cliente } from "./Cliente.js";
import { Gerente } from "./Funcionario/Gerente.js";
import { Diretor } from "./Funcionario/Diretor.js";
import { SistemaAutenticacao } from "./SistemaAutenticacao.js";

const diretor = new Diretor("Mario", 10000, 1234567890);
diretor.cadastrarSenha("1234");
const gerente = new Gerente("Joao", 5000, 9876543210);

const estaLogado = SistemaAutenticacao.login(diretor, "1234");

console.log(estaLogado);
