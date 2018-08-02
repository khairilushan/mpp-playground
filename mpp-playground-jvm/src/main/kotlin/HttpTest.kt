import com.khairilushan.mpp.datasource.ProjectDataSource
import com.khairilushan.mpp.datasource.network.SearchProjectService
import com.khairilushan.mpp.interactor.Failure
import com.khairilushan.mpp.interactor.SearchProjectInteractor
import com.khairilushan.mpp.interactor.Success
import com.khairilushan.mpp.repository.ProjectRepositoryImpl

fun main(args: Array<String>) {
  val network = ProjectDataSource.Network(SearchProjectService())
  val repository = ProjectRepositoryImpl(network)
  val interactor = SearchProjectInteractor(repository)
  val params = SearchProjectInteractor.Params("kotlin%20multiplatform")
  interactor.execute(params) {
    when (it) {
      is Success -> it.result.map { "${it.title} by ${it.author}" }.forEach { println(it) }
      is Failure -> print(it.message)
    }
  }
  Thread.sleep(5000)
}
