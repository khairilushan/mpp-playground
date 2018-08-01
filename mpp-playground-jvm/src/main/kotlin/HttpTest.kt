import com.khairilushan.mpp.datasource.ProjectDataSource
import com.khairilushan.mpp.datasource.network.ProjectService
import com.khairilushan.mpp.interactor.Failure
import com.khairilushan.mpp.interactor.SearchProjectInteractor
import com.khairilushan.mpp.interactor.Success
import com.khairilushan.mpp.repository.ProjectRepositoryImpl

fun main(args: Array<String>) {
  val network = ProjectDataSource.Network(ProjectService(ProjectService.SEARCH))
  val repository = ProjectRepositoryImpl(network)
  val interactor = SearchProjectInteractor(repository)
  interactor.execute("swift") {
    print(Thread.currentThread().name)
    when (it) {
      is Success -> print(it.result)
      is Failure -> print(it.message)
    }
  }
  Thread.sleep(3000)
}
